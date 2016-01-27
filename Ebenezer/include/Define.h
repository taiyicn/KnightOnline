#ifndef _DEFINE_H
#define _DEFINE_H

#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

#include "SDL2/SDL.h"
#include "SDL2/SDL_net.h"

const int CURRENT_VERSION = 1068; // 현재 버전

#define SUCCESS 0x02
#define MAX_PACKET_SIZE  (1024*8)
#define SOCKET_BUFF_SIZE (1024*32)
#define MONSTER_SPEED 1500
#define AI_KARUS_SOCKET_PORT 10020
#define MAX_SOCKET    100
#define MAX_AI_SOCKET 10
#define PACKET_START1 0xAA
#define PACKET_START2 0x55
#define PACKET_END1 0x55
#define PACKET_END2 0xAA




#define SERVER_INFO_START 0x01
#define SERVER_INFO_END   0x02

#define _LISTEN_PORT		10000
#define MAX_USER			3000

#define MAX_ID_SIZE			20
#define MAX_ITEM			28
#define VIEW_DIST			64		// 가시거리

////////////////////////////////////////////////////////////
// Socket Define
////////////////////////////////////////////////////////////

//#define PROTOCOL_VER				0X01

// status
#define STATE_CONNECTED			0X01
#define STATE_DISCONNECTED		0X02
#define STATE_GAMESTART			0x03

// Socket type
#define TYPE_ACCEPT				0x01
#define TYPE_CONNECT			0x02

// Overlapped flag
#define OVL_RECEIVE				0X01
#define OVL_SEND				0X02
#define OVL_CLOSE				0X03
////////////////////////////////////////////////////////////

//-----------------------------------------------------------------------------
typedef struct {
	uint16_t sCurZone;
	uint16_t sLength;
	uint8_t  pBuf[2048];
} SEND_DATA;

typedef unsigned char Byte;

typedef union{
	short int	i;
	Byte		b[2];
} MYSHORT;

typedef union{
	int			i;
	Byte		b[4];
} MYINT;

typedef union{
	unsigned int		w;
	Byte		b[4];
} MYDWORD;


// DEFINE MACRO PART...
#define BufInc(x) (x)++;(x) %= SOCKET_BUF_SIZE;

// Packet Define...

#define WIZ_LOGIN				0x01
#define WIZ_GAMESTART			0x02
#define WIZ_MOVE				0x03
#define WIZ_USERINOUT			0x04


#define N3_GAMESERVER_GROUP_LIST	0xf5
#define N3_VERSION_CHECK		0x2B	// 버전 체크... s1 - Version
#define N3_ACCOUNT_LOGIN			0xf3
#define	N3_GAME_SERVER_LOGIN	0x01	// Game server 에 Log in..
#define N3_CHECK_SPEEDHACK			0x41 // 스피드핵 체크용 패킷..
#define	N3_GAMESTART			0x0D	// Game Start..
#define	N3_ALL_CHARACTER_INFO_REQUEST	0x0C	// 모든 캐릭터 정보 요청하기..
#define	N3_CHARACTER_SELECT		0x04	// Game start..
#define	N3_MOVE					0x06	// Move..
#define N3_TIME_NOTIFY				0x39	// 패킷에서 아무것도 안보낸지 2초 지나면.. 이걸 보낸다..
#define	N3_ROTATE				0x09	// Rotate..
#define	N3_MYINFO				0x0E	// NPC moveedge..
#define N3_NOTICE				0x2E	// 공지사항..



// Reply packet define...

#define RE_USER_LOGIN			0x01
#define SERVER_ALIVE_CHECK		0x02
#define RE_CHANGE_ZONE			0x03
#define RE_USER_CLOSE			0X04

//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
//
//	Global Function Define
//

void	GetString( Byte* tBuf, Byte* sBuf, int len, int& index );
Byte	GetByte  ( Byte* sBuf, int& index );
int 	GetShort ( Byte* sBuf, int& index );
unsigned int	GetDWORD ( Byte* sBuf, int& index );
float	Getfloat ( Byte* sBuf, int& index );

void	SetString( Byte* tBuf, char* sBuf, int len, int& index );
void	SetByte  ( Byte* tBuf, Byte sByte, int& index );
void	SetShort ( Byte* tBuf, int sShort, int& index );
void	SetDWORD ( Byte* tBuf, unsigned int sWORD, int& index);
void	Setfloat ( Byte* tBuf, float sFloat, int& index );
int		ParseSpace( Byte* tBuf, Byte* sBuf );

std::string GetProgPath();

#endif
