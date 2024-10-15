#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<tchar.h>
#include<thread>
#include<string>

using namespace std;

#pragma comment(lib,"ws2_32.lib")

/*
initialize winsock library

create the socket

Connect to the server

send and recv

close the socket

cleanup the winsock
*/

bool initialize() {
	WSAData data;
	return WSAStartup(MAKEWORD(2, 2), &data) == 0;
}

void sendMessage(SOCKET s) {
	cout << "Enter your chat name : " << endl;
	string name{}, message{};
	getline(cin, name);
	while (1) {
		getline(cin, message);
		string msg = name + " : " + message;
		int byteSend = send(s, msg.c_str(), msg.length(), 0);
		if (byteSend == SOCKET_ERROR) {
			cout << "Error Sending the messsage " << endl;
			break;
		}

		if (message == "quit") {
			cout << "Stopping the application." << endl;
			break;
		}
	}
	closesocket(s);
	WSACleanup();
}

void recieveMessage(SOCKET s) {
	char buffer[4096]{};
	int recvLength{};
	string msg{};
	while (1) {
		recvLength = recv(s, buffer, sizeof(buffer), 0);
		if (recvLength <= 0) {
			cout << "Disconnected from the server" << endl;
			break;
		}
		else {
			msg = string(buffer, recvLength);
			cout << msg << endl;
		}
	}
	closesocket(s);
	WSACleanup();
}

int main() {
	cout << "Client Program" << endl;

	if (!initialize()) {
		cout << "Winsock initialization failed " << endl;
		return 1;
	}

	string serverAddress = "127.0.0.1";
	int port = 12345;

	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocket == INVALID_SOCKET) {
		cout << "Socket Creation Failed" << endl;
		return 1;
	}

	//create address structure
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);

	//Convert the ip address to binary format
	if (inet_pton(AF_INET, serverAddress.c_str(), &serverAddr.sin_addr) != 1) {
		cout << "Settign Address Structure Failed" << endl;
		closesocket(clientSocket);
		WSACleanup();
		return 1;
	}

	if (connect(clientSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
		cout << "Not able to connect to server " << endl;
		closesocket(clientSocket);
		WSACleanup();
		return 1;
	}

	cout << "Successfully connected to server " << endl;

	thread senderThread(sendMessage, clientSocket);
	thread reciverThread(recieveMessage, clientSocket);

	senderThread.join();
	reciverThread.join();

	return 0;
}
