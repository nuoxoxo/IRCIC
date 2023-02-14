FROM		debian:buster

# RUN		apk update && \
#		apk upgrade && \
#		apk add openssl && \
#		apk add --no-cache nginx && \
#		mkdir -p /var/www/html/ && \
#		rm -rf /var/lib/apt/lists/*

RUN		apt-get update -y && \
		apt-get install -y \
		nginx openssl && apt-get clean && \
		rm -rf /var/lib/apt/lists/* && \
		mkdir -p /etc/nginx/ssl

COPY		./conf/nginx.conf /etc/nginx/conf.d

RUN		mkdir -p /etc/nginx/ssl && \
		openssl req \
		-newkey rsa:4096 \
		-x509 \
		-sha256 \
		-days 365 \
		-nodes \
		-subj "/C=FR/ST=Paris/L=Paris/O=School42/CN=localhost" \
		-keyout /etc/nginx/ssl/nuxu.42.fr.key \
		-out /etc/nginx/ssl/nuxu.42.fr.crt

# RUN		apk add openrc && \
# 		rc-update add nginx default
# RUN		apt-get openrc && rc-update add nginx default

EXPOSE		443

CMD		["nginx", "-g", "daemon off;"]
# daemon off means nginx runs in the foreground
