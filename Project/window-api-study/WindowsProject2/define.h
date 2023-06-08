#pragma once

// Mgr Ŭ�������� ���α׷��� ����Ǵ� ���ȿ� �ϳ��� �����ؾ� �ϱ� ������
// �̱��� ������ ���� ���� ��ó����� ����� �ξ����ϴ�
#define SINGLE(type) public:\
					 static type* GetInstance()\
					{\
						static type mgr;\
						return &mgr;\
					}\
					 private:\
						type(); \
						~type();

// ������ ���� �Դϴ�
const double PI = -3.1415926535;

const int BOARD_TILE = 120;
const int BOARD_SIZE_COL = 13;
const int BOARD_SIZE_ROW = 9;
const int BOARD_PENDING = 3;


// Object Ÿ���Դϴ�. 
// Object �� �߰��� ��쿡 ���⿡ Type�� �߰����־�� �մϴ�.
enum class GROUP_TYPE
{
	DEFAULT,				// �⺻
	BACKGROUND,
	TILE,					// Ÿ�� ( �߰� : �̰��� )
	TILE_APPERENCE,
	MONSTER,				// ����
	MONSTER_ABSOLUTE,		// ������ ����
	PROJ_PLAYER,			// �÷��̾� ����ü
	PROJ_MONSTER,			// ���� ����ü
	PROJ_MONSTER_ABLSOLUTE,	// ������ ���� ����ü
	TRAP_FIRE,				// ���� ( �� )
	TRAP_ARROW,				// ���� ( ȭ�� )
	RELICS,					// ����
	LEVER,					// ����
	DOOR,					// ��
	PLAYER,					// �÷��̾�
	PANEL_UI ,


	Event_UI = 30,
	UI = 31,
	END = 32,
};

// Scene Ÿ���Դϴ�.
// Scene �� �߰��� ��쿡 ���⿡ Type�� �߰����־�� �մϴ�.
enum class SCENE_TYPE
{
	TITLE,			// ����â
	TOOL,				// �� ��
	TEST,
	SELCETMAP,
	CUTSCENE,
	START,				// ��ŸƮ ��

	STAGE_1_1,			
	STAGE_1_2,		
	STAGE_1_3,
	STAGE_1_5,
	STAGE_1_6,
	STAGE_1_7,
	STAGE_1_8,

	STAGE_2_1,
	STAGE_2_2,
	STAGE_2_3,
	STAGE_2_4,
	STAGE_2_5,
	STAGE_2_6,

	STAGE_3_1,
	STAGE_3_2,

	STAGE_END,

	ENDING,
	CREDIT,
	END,
};

// �귯�� Ÿ���Դϴ�.
enum class BRUSH_TYPE
{
	HOLLOW,
	RED,
	END,
};

// �� Ÿ���Դϴ�
enum class PEN_TYPE
{
	RED,
	GREEN,
	BLUE,
	BLACK,
	WHITE,
	PUPLE,
	YELLOW,
	ORENGE,
	END,
};

// �̺�Ʈ Ÿ���Դϴ�.
// �̺�Ʈ�� �߰��� ��쿡 ���⿡ TYPE�� �߰��� �־�� �մϴ�.
enum class EVENT_TYPE
{
	CREATE_OBJECT,		// ������Ʈ ������ ��,
	DELETE_OBJECT,		// ������Ʈ ������ ��
	SCENE_CHANGE,		// ���� ����� ��
	SCENE_SWAP,
	TRIGGER_ON,			// Ʈ���Ű� �߻��� ��
	LEVERTRIGGER_ON,	// ���� Ʈ���Ű� �߻��� ��

	END
};

enum class OBJECT_DIR
{
	UP,
	LEFT,
	RIGHT,
	DOWN
};

// Ÿ�� Ÿ�Կ� ���� �ݸ��� ó��
enum class TILE_TYPE
{
	MOVABLE = 0,
	WALL,
	FATAL,
	TRAP,
	POSION,
	FIRE,
	SCENE_CHANGE,
	TRIGGER,
	END,
	TRIGGER_FATAL,
	TRIGGER_MOVABLE,
};

enum class MONSTER_STATE
{
	IDLE,
	CHASE,
	DELAY,
	STUN
};

enum class DRAIN_STATE
{
	DRAIN1,
	DRAIN2,
	DRAIN3,
};