project		:= inception
env_file	:= ./srcs/.env
compose_file	:= ./srcs/docker-compose.yml

all	:
	@ echo " ➜ Build and launch ${project} ... "
	@ mkdir -p /home/${USER}/data/wordpress /home/${USER}/data/mariadb
	@ docker-compose -f $(compose_file) up --build -d

down	:
	@ echo " ➜ Stopping ${project} ... "
	@ docker-compose -f $(compose_file) down

re	: fclean all

ls	:
	@ echo "\t< images >"
	@ docker image ls -a
	@ echo "\t< containers >"
	@ docker container ls
	@ echo "\t< volumes >"
	@ docker volume ls -q
	@ echo "\t< network >"
	@ docker network ls

clean	: down
	@ echo " ➜ Cleaning up ... "
	@-docker-compose -f $(compose_file) down
	@ docker stop `docker ps -qa`
	@ docker rm `docker ps -qa`
	@ echo " ➜ Delete all images ... "
	@ docker rmi -f `docker images -qa`
	@ echo " ➜ Delete all volumes ... "
	@ docker volume rm `docker volume ls -q`
	@ echo " ➜ Delete all network ... "
	@ docker network rm `docker network ls -q`
	@ echo " ➜ Delete all data ... "
	@ sudo rm -rf /home/$(USER)/data/wordpress
	@ sudo rm -rf /home/$(USER)/data/mysql
	@ echo " ➜ Cleanup completed. "

f	: clean

.PHONY	: all re ls down clean 
