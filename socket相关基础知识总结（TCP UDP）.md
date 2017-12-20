socket相关基础知识总结（TCP UDP）

一、概述
    Socket编程大体上包括Tcp Socket、Udp Socket和Raw Socket这三种，其中TCP和UDP方式的Socket编程用于编写应用层的socket程序，是我们用得比较多的，
    
而Raw Socket则用得相对较少。

    TCP（传输控制协议）和UDP（用户数据报协议是网络体系结构TCP/IP模型中传输层一层中的两个不同的通信协议。

    TCP：传输控制协议，一种面向连接的协议，给用户进程提供可靠的全双工的字节流，TCP套接口是字节流套接口(stream socket)的一种。

    UDP：用户数据报协议。UDP是一种无连接协议。UDP套接口是数据报套接口(datagram socket)的一种。

二、TCP和UDP介绍

1）基本TCP客户—服务器程序设计基本框架
