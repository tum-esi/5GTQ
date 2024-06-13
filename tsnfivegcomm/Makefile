all: checkmakefiles
	@cd src && $(MAKE)

clean: checkmakefiles
	@cd src && $(MAKE) clean

cleanall: checkmakefiles
	@cd src && $(MAKE) MODE=release clean
	@cd src && $(MAKE) MODE=debug clean
	@rm -f src/Makefile

makefiles:
	@cd src && opp_makemake --make-so -f --deep -o tsnfivegcomm -O out -KINET_PROJ=$$(inet_root) -DINET_IMPORT -I. -I$$\(INET_PROJ\)/src -L$$\(INET_PROJ\)/src -lINET$$\(D\) -KSIMU5G_PROJ=$$SIMU5G_ROOT -DSIMU5G_IMPORT -I. -I$$\(SIMU5G_PROJ\)/src -L$$\(SIMU5G_PROJ\)/src -lsimu5g$$\(D\)

checkmakefiles:
	@if [ ! -f src/Makefile ]; then \
	echo; \
	echo '======================================================================='; \
	echo 'src/Makefile does not exist. Please use "make makefiles" to generate it!'; \
	echo '======================================================================='; \
	echo; \
	exit 1; \
	fi
