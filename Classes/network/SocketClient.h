#ifndef _SocketClient_H__
#define _SocketClient_H__
#define ASIO_STANDALONE
#include "asio.hpp"
#include <functional>
#include <thread>
#include <chrono>
#include "cocos2d.h"
#include <deque>
#include <iostream>
#include "socket_message.h"
#include<network/GameMessage.pb.h>
#include<network/GameMessageWrap.h>
using asio::ip::tcp;

class SocketClient
{
public:
	static SocketClient* create(std::string ip = "127.0.0.1", int port = 8008);
	void close();                                                                 //�ر�
	void start()                                                                  //����
	{
		start_connect();
	};
	std::vector<GameMessage> get_game_messages();
	void send_game_message(const std::vector<GameMessage>& vec_game_msg);
	void send_string(std::string s);                                              //��������
	std::string get_string();                                                     //��ȡ����
	void do_close();     //inner use
	bool started() const { return start_flag_; }                                  //��Ϸ�Ƿ�ʼ
	bool error()const { return error_flag_; }                                     //�Ƿ����쳣
	int camp() const;                                                             //���������Ӫ
	int total() const;                                                            //�����������
private:
	SocketClient::SocketClient(std::string ip, int port) : socket_(io_service_), endpoint_(asio::ip::address_v4::from_string(ip), port)
	{
		start();
	}
	void write_data(std::string s);                                            //д������
	void start_connect();                                                      //��ʼ����
	void handle_connect(const asio::error_code& error);                        //��������
	void handle_read_header(const asio::error_code& error);                    //����ͷ  
	void handle_read_body(const asio::error_code& error);                      //������
	std::string read_data();
private:
	asio::io_service io_service_;
	tcp::socket socket_;
	tcp::endpoint endpoint_;
	std::deque<socket_message> read_msg_deque_;
	socket_message read_msg_;
	bool start_flag_{ false }, error_flag_{ false };
	std::thread *thread_, *read_thread_;
	int camp_, total_;
	std::condition_variable data_cond_;
	std::mutex mut;
};







#endif // !_SocketClient_H__

