FROM		alpine:3.16

ARG		DB_NAME \
		DB_USER \
		DB_PASS

RUN		apk update && apk add --no-cache  mariadb  mariadb-client
		# --no-cache means no caching

		# First layer - normalize the config
RUN		mkdir /var/run/mysqld; \
		chmod 777 /var/run/mysqld; \
		{ \
			echo '[mysqld]'; \
			echo 'skip-host-cache'; \
			echo 'skip-name-resolve'; \
			echo 'bind-address=0.0.0.0'; \
		} \
		| \
		tee /etc/my.cnf.d/docker.cnf; \
		sed -i	"s|skip-networking|skip-networking=0|g" \
			/etc/my.cnf.d/mariadb-server.cnf
		# tee : send output of echo to a file
		# (??) why use `skip-networking=0`

		# Second layer : create DB, set path based on Layer 1
RUN		mysql_install_db	\
		--user=mysql		\
		--datadir=/var/lib/mysql

EXPOSE		3306
		# open mariaDB working port


# under previously created `mysql` we start up the DB

#USER		mysql
#COPY		requirements/mariadb/conf/create_db.sh . 
		# ⤷ changed
#RUN		sh create_db.sh && rm create_db.sh
		# ⤷ added

COPY		requirements/mariadb/conf/create_db.sh .
RUN		sh create_db.sh && rm create_db.sh
USER		mysql
CMD		["/usr/bin/mysqld", "--skip-log-error"]

#EXPOSE		3306
#USER		mysql
#COPY		requirements/mariadb/conf/create_db.sh .
# COPY		conf/create_db.sh . 
#ENTRYPOINT	["sh", "create_db.sh"]
#CMD		["/usr/bin/mysqld", "--skip-log-error"]
