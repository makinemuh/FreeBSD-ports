# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pystorm
PORTVERSION=	3.1.0
PORTREVISION=	0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Battle-tested Apache Storm Multi-Lang implementation for Python

LICENSE=	APACHE20

USES=		python
USE_PYTHON=	autoplist distutils

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>0:devel/py-simplejson
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}msgpack-python>0:devel/py-msgpack-python

NO_ARCH=	yes

post-patch:
	${RM} ${WRKSRC}/test/__init__.py

.include <bsd.port.mk>
