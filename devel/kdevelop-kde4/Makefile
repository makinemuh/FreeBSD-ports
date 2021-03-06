# Created by: Golyashov Sergei <svvord@mail.ru>
# $FreeBSD$

PORTNAME=	kdevelop
DISTVERSION=	${KDEVELOP_VERSION}
PORTREVISION=	3
CATEGORIES=	devel kde
MASTER_SITES=	KDE/${KDEVELOP_BRANCH}/kdevelop/${DISTVERSION}
DIST_SUBDIR=	KDE/kdevelop/${KDEVELOP_VERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plugin extensible IDE for KDE

LIB_DEPENDS=	libkdevplatforminterfaces.so:devel/kdevplatform
RUN_DEPENDS=	gmake:devel/gmake

USES=		cmake:outsource compiler:c++11-lib kde:4 \
		shared-mime-info tar:xz
USE_KDE=	kdelibs workspace automoc4
USE_QT4=	qmake_build moc_build uic_build rcc_build \
		corelib declarative gui help script webkit xml

OPTIONS_DEFINE=	OKTETA PHP NLS
OPTIONS_DEFAULT=	OKTETA PHP
OPTIONS_SUB=	yes

OKTETA_DESC=	Hex editing support via Okteta
OKTETA_LIB_DEPENDS=	libokteta1core.so:devel/okteta
OKTETA_CMAKE_OFF=	-DWITH_LibOktetaKasten:BOOL=OFF
OKTETA_CMAKE_ON=	-DWITH_LibOktetaKasten:BOOL=ON

PHP_DESC=	PHP support for KDevelop
PHP_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/kdevphplanguagesupport.so:devel/kdevelop-php

NLS_USES=	gettext
NLS_CMAKE_OFF=	-DBUILD_po:BOOL=FALSE

post-patch:
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/app/CMakeLists.txt

.include <bsd.port.mk>
