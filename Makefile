# Top level makefile to build all projects
all:
	cd inet && make makefiles && $(MAKE)
	cd Simu5G && make makefiles && $(MAKE)
	cd tsnfivegcomm && make makefiles && $(MAKE)
