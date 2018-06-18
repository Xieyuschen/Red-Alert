<<<<<<< HEAD

#ifndef CHAT_MESSAGE_HPP
#define CHAT_MESSAGE_HPP
=======
//���ݴ���  ����Ϣǰ�����ĸ��ֽڵ���Ϣͷ����ʶ��Ϣ����
//��Դ��asio �ٷ�ʾ�� src\examples\cpp11\chat\chat_message.hpp
#ifndef _SocketMessage_H__
#define _SocketMessage_H__
>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151

#include <cstdio>
#include <cstdlib>
#include <cstring>

class socket_message
{
public:
	enum{header_length = 4};
	enum{max_body_length = 8192};
	socket_message()
		: body_length_(0)
	{
	}
<<<<<<< HEAD
	const char* data() const
	{
		return data_;
	}
	char* data()
	{
		return data_;
	}
	size_t length() const
	{
		return header_length + body_length_;
	}
	const char* body() const
	{
		return data_ + header_length;
	}
	char* body()
	{
		return data_ + header_length;
	}
	size_t body_length() const
	{
		return body_length_;
	}
	void body_length(size_t new_length)
=======
	const char* data() const                                    //��ȡȫ����Ϣ
	{
		return data_;
	}
	char* data()                                                //��ȡ�ɸı����Ϣ
	{
		return data_;
	}
	size_t length() const                                       //��ȡ��Ϣ����
	{
		return header_length + body_length_;
	}
	const char* body() const                                    //��ȡ��Ϣ����
	{
		return data_ + header_length;
	}
	char* body()                                                //��ȡ�ɸı����Ϣ����
	{
		return data_ + header_length;
	}
	size_t body_length() const                                  //��ȡ���ݳ���
	{
		return body_length_;
	}
	void body_length(size_t new_length)                         //�������ݳ���
>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151
	{
		body_length_ = new_length;
		if (body_length_ > max_body_length)
			body_length_ = max_body_length;
	}
<<<<<<< HEAD
	bool decode_header()
=======
	bool decode_header()                                        //����ͷ
>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151
	{
		using namespace std; // For strncat and atoi.
		char header[header_length + 1] = "";
		strncat(header, data_, header_length);
		body_length_ = atoi(header);
		if (body_length_ > max_body_length)
		{
			body_length_ = 0;
			return false;
		}
		return true;
	}
<<<<<<< HEAD
	void encode_header()
=======
	void encode_header()                                         //����ͷ�������ݳ���д����Ϣͷ��
>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151
	{
		using namespace std; // For sprintf and memcpy.
		char header[header_length + 1] = "";
		sprintf(header, "%4d", static_cast<int>(body_length_));
		memcpy(data_, header, header_length);
	}
private:
	char data_[header_length + max_body_length];
	size_t body_length_;
};

<<<<<<< HEAD
#endif // CHAT_MESSAGE_HPP
=======
#endif // !_SocketMessage_H__
>>>>>>> 34360dbd6820c2083d37348657fa6d8677657151
