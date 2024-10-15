#include<iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
#include<tchar.h>
#include<thread>
#include<vector>

using namespace std;

#pragma comment(lib,"ws2_32.lib")

/*
//initialize winsock library

//create the socket

//get ip and port

//bind the ip/port with the socket

//listen on the socket

// accept

//recv and send

//close the socket

//cleanup the winsock
*/

bool initialize() {
	WSAData data;
	return WSAStartup(MAKEWORD(2, 2), &data) == 0;
}

void interactWithClient(SOCKET clientSocket, vector<SOCKET>& clients) {
	cout << "Client Connected" << endl;
	char buffer[4096];

	while (1) {
		int byteRecved = recv(clientSocket, buffer, sizeof(buffer), 0);
		if (byteRecved <= 0) {
			cout << "Client Disconnected" << endl;
			break;
		}

		string message(buffer, byteRecved);
		cout << "Message from client : " << message << endl;

		for (auto client : clients) {
			if (client != clientSocket) {
				send(client, message.c_str(), message.length(), 0);
			}
		}
	}

	auto it = find(clients.begin(), clients.end(), clientSocket);
	if (it != clients.end())
		clients.erase(it);

	closesocket(clientSocket);
}

int main() {
	cout << "Server Program" << endl;

	if (!initialize()) {
		cout << "winsock initialization failed " << endl;
		return 1;
	}

	SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocket == INVALID_SOCKET) {
		cout << "Socket Creation Failed" << endl;
		return 1;
	}

	//create address structure
	int port = 12345;
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);

	//Convert the ip address to binary format
	if(InetPton(AF_INET, _T("0.0.0.0"), &serverAddr.sin_addr) != 1){
		cout << "Settign Address Structure Failed" << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	//bind
	if (bind(listenSocket, reinterpret_cast<sockaddr*>(&serverAddr), sizeof(serverAddr)) == SOCKET_ERROR) {
		cout << "Bind Faled" << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	//listen
	if (listen(listenSocket, SOMAXCONN) == SOCKET_ERROR) {
		cout << "Listen Failed" << endl;
		closesocket(listenSocket);
		WSACleanup();
		return 1;
	}

	cout << "Server has started listning on port : " << port << endl;
	vector<SOCKET>clients{};

	while (1) {
		//accept
		SOCKET clientSocket = accept(listenSocket, nullptr, nullptr);
		if (clientSocket == INVALID_SOCKET) {
			cout << "Invalid clien socket" << endl;
			closesocket(listenSocket);
			WSACleanup();
			return 1;
		}
		clients.push_back(clientSocket);
		thread t1(interactWithClient, clientSocket,ref(clients));
		t1.detach();
	}

	closesocket(listenSocket);

	WSACleanup();
	return 0;
}
