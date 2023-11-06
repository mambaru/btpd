FROM debian
ENV LANG ru_RU.UTF-8
ENV TZ="Europe/Moscow"
RUN apt update  && apt install  -y libsnappy1v5
RUN apt -y install g++ cmake git wget
RUN groupadd -g 80 www && useradd -u 30 --shell /sbin/nologin --group www wwwrun;
RUN mkdir /bptd
COPY . /btpd/
RUN cd /btpd && make release
USER wwwrun
EXPOSE 38001 38001/udp 38000 38000/udp 37000 37001 37002 37003 37004
CMD ["/btpd/build/bin/btpd", "-V", "/btpd/examples/simple/btp.conf"]