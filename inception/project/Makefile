project		:= inception
compose_fil	:= ./srcs/docker-compose.yml

all	:
	@ echo " ➜ Build and launch ${project} ... "
	@ mkdir -p /home/${USER}/data/wordpress /home/${USER}/data/mariadb
	@ docker-compose -f ./srcs/docker-compose.yml up --env-file ./srcs/.env --build -d

down	:
	@ echo " ➜ Stopping ${project} ... "
	@ docker-compose -f ./srcs/docker-compose.yml down

re	: fclean all

ls	:
	@ echo "\timages ...\n"
	docker image ls -a
	@ echo "    containers ...\n"
	docker container ls
	@ echo "    volumes ...\n"
	docker volume ls -q
	@ echo "    network...\n"
	docker network ls

clean	: down
	@ echo " ➜ Cleaning up ... "
	@docker-compose -f $(COMPOSE_FILE) down
	@-docker stop `docker ps -qa`
	@-docker rm `docker ps -qa`
	@echo "$(RED)Deleting all images ... $(RESET)"
	@-docker rmi -f `docker images -qa`
	@echo "$(RED)Deleting all volumes ... $(RESET)"
	@-docker volume rm `docker volume ls -q`
	@echo "$(RED)Deleting all network ... $(RESET)"
	@-docker network rm `docker network ls -q`
	# @echo "$(RED)Deleting all data ... $(RESET)"
	# @sudo rm -rf /home/nuxu/data/wordpress
	# @sudo rm -rf /home/nuxu/data/mysql
	# @echo "$(RED)Deleting all $(RESET)"
f	: fclean

.PHONY	: all re ls down clean fclean
