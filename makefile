 

main: init code script

init : 
	mkdir ~/liveupdate

code : 
	gcc ./liveupdate.c  -o  liveupdate 
	mv ./liveupdate ~/liveupdate


script : 
	cp ./uptex.sh ~/liveupdate 

clean:
	rm -f ./*.o 
