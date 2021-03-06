--- chrome/app/shutdown_signal_handlers_posix.cc.orig	2017-06-05 19:03:01 UTC
+++ chrome/app/shutdown_signal_handlers_posix.cc
@@ -183,6 +183,11 @@ void InstallShutdownSignalHandlers(
   g_pipe_pid = getpid();
   g_shutdown_pipe_read_fd = pipefd[0];
   g_shutdown_pipe_write_fd = pipefd[1];
+#if defined(OS_BSD)
+  // PTHREAD_STACK_MIN causes chromium to crash under FreeBSD,
+  // we request the default pthread stack size by specifying 0 here.
+  const size_t kShutdownDetectorThreadStackSize = 0;
+#else 
 #if !defined(ADDRESS_SANITIZER) && !defined(KEEP_SHADOW_STACKS)
   const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 2;
 #else
@@ -190,6 +195,7 @@ void InstallShutdownSignalHandlers(
   // shadow stacks) bloat the stack frames, so we need to increase the stack
   // size to avoid hitting the guard page.
   const size_t kShutdownDetectorThreadStackSize = PTHREAD_STACK_MIN * 4;
+#endif
 #endif
   ShutdownDetector* detector = new ShutdownDetector(
       g_shutdown_pipe_read_fd, shutdown_callback, task_runner);
