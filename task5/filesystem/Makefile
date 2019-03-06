

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

rundelete:linkdelete
	./delete.run
	rm ./delete.run

linkdelete:models.c models.h utils.c utils.h delete.c delete.h
	cc -o delete.run models.c utils.c delete.c

runwrite:linkwrite
	./write.run
	rm ./write.run
linkwrite:models.c models.h utils.c utils.h directory.h directory.c write.c write.h
	cc -o write.run models.c utils.c directory.c write.c

runread:linkread
	./read.run
	rm ./read.run

linkread:models.c models.h utils.c utils.h directory.h directory.c read.c read.h
	cc -o read.run	models.c utils.c directory.c read.c




