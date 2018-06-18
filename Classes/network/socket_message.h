//���ݴ���  ����Ϣǰ�����ĸ��ֽڵ���Ϣͷ����ʶ��Ϣ����
//��Դ��asio �ٷ�ʾ�� src\examples\cpp11\chat\chat_message.hpp
#ifndef _SocketMessage_H__
#define _SocketMessage_H__

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
	{
		body_length_ = new_length;
		if (body_length_ > max_body_length)
			body_length_ = max_body_length;
	}
	bool decode_header()                                        //����ͷ
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
	void encode_header()                                         //����ͷ�������ݳ���д����Ϣͷ��
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

#endif // !_SocketMessage_H__
