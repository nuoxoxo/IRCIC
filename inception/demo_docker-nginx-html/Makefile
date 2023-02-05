name	:= demo_docker-nginx-html

all	:
	@ echo "Launch configuration ${name}... "
	@ docker-compose -f ./docker-compose.yml up -d

build	:
	@ echo "Building configuration ${name}... "
	@ docker-compose -f ./docker-compose.yml up -d --build

down	:
	@ echo "Stopping configuration ${name}... "
	@ docker-compose -f ./docker-compose.yml down

re	: down
	@ echo "Rebuild configuration ${name}... "
	@ docker-compose -f ./docker-compose.yml up -d --build

clean	: down
	@ echo "Cleaning configuration ${name}... "
	@ docker system prune -a

fclean	:
	@ echo "Total clean of all configurations docker "
	@ docker stop $$(docker ps -qa)
	@ docker system prune --all --force --volumes
	@ docker network prune --force
	@ docker volume prune --force

.PHONY	: all build down re clean fclean
