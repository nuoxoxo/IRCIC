# FROM		alpine:3.16
FROM		debian:buster

RUN		apk update && \
		apk install --no-cache mariadb mariadb-client mariadb-server

# RUN		apt-get update && \
#		apt-get install -y mariadb-server mariadb-client && \
#		apt-get clean && rm -rf /var/lib/apt/lists/*

#ARG		DB_NAME \
#		DB_USER \
#		DB_PASS

COPY		./conf/mysql.cnf /etc/mysql/mysql.cnf
COPY		./tools/db-config-create.sh /etc/

RUN		chmod +x /etc/db-config-create.sh && \
		mkdir -p /run/mysqld/ && \
		chown -R mysql /run/mysqld && \
		chmod -R 755 /var/lib/mysql

#EXPOSE		3306
#USER		mysql
#COPY		requirements/mariadb/conf/create_db.sh .
# COPY		conf/create_db.sh . 
#ENTRYPOINT	["sh", "create_db.sh"]
#CMD		["/usr/bin/mysqld", "--skip-log-error"]

EXPOSE		3306

CMD		["sh", "/etc/db-config-create.sh"]
