FROM	debian:buster

RUN	apt-get update && apt-get install -y mariadb-server mariadb-client && \
	apt-get clean && rm -rf /var/lib/apt/lists/*

COPY	./conf/my.cnf /etc/mysql/my.cnf
COPY	./tools/db-setup.sh /etc/

RUN	chmod +x /etc/db-setup.sh && \
	mkdir -p /run/mysqld/ && \
	chown -R mysql /run/mysqld && \
	chmod -R 755 /var/lib/mysql

EXPOSE	3306

CMD	["sh", "/etc/db-setup.sh"]

