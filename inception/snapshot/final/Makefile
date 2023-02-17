project		:= inception
compose_file	:= ./srcs/docker-compose.yml
# env_file	:= /srcs/.env

all :
	mkdir -p /home/${USER}/data/wordpress /home/${USER}/data/mariadb
	docker-compose -f $(compose_file) up --build -d

up :
	docker-compose -f $(compose_file) up -d

down :
	docker-compose -f $(compose_file) down

clean :	down
	@ echo " ➜ Cleaning up ... "
	@ docker system prune -af --volumes
	@ docker volume rm $$(docker volume ls -q)
	@ echo " ➜ Delete all data ... "
	@ sudo rm -rf /home/$(USER)/data
	@#@ sudo rm -rf /home/$(USER)/data/wordpress
	@#@ sudo rm -rf /home/$(USER)/data/mariadb
	@ echo " ➜ Cleanup completed. "

f	: clean

re : f all

ls :
	@ echo "\t... images ..."
	@ docker image ls
	@ echo "\t... containers ..."
	@ docker container ls
	@ echo "\t... volumes ..."
	@ docker volume ls -q
	@ echo "\t... network ..."
	@ docker network ls


.PHONY:	all down clean fclean re
