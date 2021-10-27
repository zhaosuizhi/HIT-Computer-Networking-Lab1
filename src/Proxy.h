//
// Created by jiabh on 2021/10/26.
//

#ifndef HTTP_PROXY_SERVER_PROXY_H
#define HTTP_PROXY_SERVER_PROXY_H

#include "http_message/Request.h"
#include "http_message/Response.h"

class Proxy
{
protected:
	int client_sock; // 与客户端间的套接字
	int target_sock; // 与目标服务器间的套接字

	Request client_request;
	Response target_response;

public:
	/**
	 * 已经accept客户端连接的套接字
	 *
	 * @param client_sock 与客户端连接的套接字
	 */
	explicit Proxy(int client_sock);

	/**
	 * 开始代理
	 */
	void run();

private:
	int load_request();

	int forward_request();

	int load_response();

	int forward_response();
};


#endif //HTTP_PROXY_SERVER_PROXY_H
