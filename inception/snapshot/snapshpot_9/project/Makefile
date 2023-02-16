project	:= inception

all	:
	@ echo " ➜ Build and launch ${project} ... "
	@ mkdir -p /home/${USER}/data/wordpress /home/${USER}/data/mariadb
	@ docker-compose -f ./srcs/docker-compose.yml up --build -d

down	:
	@ echo " ➜ Stopping ${project} ... "
	@ docker-compose -f ./srcs/docker-compose.yml down

re	: fclean all

ls	:
	@ echo "\timages ...\n"
	docker image ls
	@ echo "    containers ...\n"
	docker container ls
	@ echo "    volumes ...\n"
	docker volume ls -q
	@ echo "    network...\n"
	docker network ls

clean	: down
	@ echo " ➜ Cleaning up ... "
	@ docker system prune -af --volumes
	@ docker volume rm $$(docker volume ls -q)
 
fclean	: clean
	@ echo " ➜ Cleaning up ..."
	@ sudo rm -rf /home/${USER}
	@ docker ps

f	: fclean

.PHONY	: all re ls down clean fclean
