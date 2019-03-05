

runinit:linkinit
	./init.run
	rm ./init.run

linkinit:init.c
	cc -o init.run models.c ./init.c 

runcreate:linkcreate
	./create.run
	rm ./create.run

linkcreate:create.c models.c models.h utils.h utils.c
	cc -o create.run  utils.c models.c create.c 

rundirectory:linkdirectory
	./directory.run
	rm ./directory.run

linkdirectory:directory.h directory.c models.h	models.c
	cc -o directory.run	models.c utils.c directory.c


