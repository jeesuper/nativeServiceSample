Ŀ¼�ṹ��
nativeBinderSample/
������ Android.mk
������ client
��   ������ Android.mk
��   ������ XmanClient.cpp
������ common
��   ������ IXmanService.cpp
��   ������ IXmanService.h
������ readme.txt
������ server
    ������ Android.mk
    ������ XmanServer.cpp

IXmanService.cpp�������� BpXmanService   BnXmanService


���̣�
client  ---------------------   server
    |                              |
    |                              |
    |                              |
BpXmanService  -------------  BnXmanService
    |                           |
    |remote()->transact         | onTransact
    |                           |
- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ������������ҵ��㣬����Ҫ�û���ʵ�ֵĴ���
    |                           |
BpBinder     -------------    BBinder 
        |                     |
             binder driver




��������bin�ļ�����ӡ���£�
01-30 16:33:41.028 D/XmanServer( 6873): XManService
01-30 16:33:43.220 D/XmanClient( 6875): begin getValue
01-30 16:33:43.220 D/IXmanService( 6875): BpXmanService---getValue---transact
01-30 16:33:43.221 D/IXmanService( 6873): BnXmanService---getValue---onTransact
01-30 16:33:43.221 D/XmanServer( 6873): getValue
01-30 16:33:43.221 D/XmanClient( 6875): Read original value from XmanService:0
01-30 16:33:43.221 D/XmanClient( 6875): Add value 6 to XmanService
01-30 16:33:43.221 D/IXmanService( 6875): BpXmanService---setValue---transact
01-30 16:33:43.221 D/IXmanService( 6873): BnXmanService---setValue---onTransact
01-30 16:33:43.221 D/XmanServer( 6873): setValue:6
01-30 16:33:43.221 D/XmanClient( 6875): begin getValue again
01-30 16:33:43.221 D/IXmanService( 6875): BpXmanService---getValue---transact
01-30 16:33:43.221 D/IXmanService( 6873): BnXmanService---getValue---onTransact
01-30 16:33:43.221 D/XmanServer( 6873): getValue
01-30 16:33:43.221 D/XmanClient( 6875): Read the value from XmanService again:6
