FROM debian:buster

RUN apt-get update && apt-get install -y mariadb-server mariadb-client && \
	apt-get clean && rm -rf /var/lib/apt/lists/*

COPY ./conf/my.cnf /etc/mysql/my.cnf
COPY ./db_script.sh /etc/

RUN chmod +x /etc/db_script.sh && \
	mkdir -p /run/mysqld/ && \
	chown -R mysql /run/mysqld && \
	chmod -R 755 /var/lib/mysql

EXPOSE 3306

CMD ["sh", "/etc/db_script.sh"]
