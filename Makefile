OBJDIR?=	build

CMAKE?=	cmake
CTEST?=	ctest

all: build
.PHONY: all

test: build
	cd ${OBJDIR} && ${CTEST} -V
.PHONY: test

build:
	${CMAKE} --build ${OBJDIR}
.PHONY: build

clean:
	${CMAKE} --build ${OBJDIR} --target clean
.PHONY: clean
