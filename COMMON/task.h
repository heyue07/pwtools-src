#pragma once

using namespace System;
using namespace System::IO;
using namespace System::Text;
using namespace System::Windows::Forms;

String^ decrypt(int key, array<unsigned char>^ text);
array<unsigned char>^ encrypt(int key, String^ text, int length, bool appendZero);
String^ ByteArray_to_HexString(array<unsigned char>^ value);
array<unsigned char>^ HexString_to_ByteArray(String^ value);
public ref struct Item
{
	int id;
	bool unknown;
	int amount;
	float probability;
	int expiration;
};

public ref struct ItemGroup
{
	bool unknown;
	int items_count;
	array<Item^>^ items;
};

public ref struct Chase
{
	int id_monster;
	int amount_monster;
	int id_drop;
	int amount_drop;
	unsigned char unknown_1;
	float probability;
	unsigned char unknown_2;
	array<unsigned char>^ unknown_3;
};

public ref struct Date
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int weekday;
};

public ref struct DateSpan
{
	Date^ from;
	Date^ to;
};

public ref struct Location
{
	int map_id;
	float x;
	float altitude;
	float z;
};

public ref struct Span
{
	float east;
	float bottom;
	float south;
	float west;
	float top;
	float north;
};

public ref struct LocationSpan
{
	int map_id;
	int count;
	array<Span^>^ spans;
};

public ref struct TeamMembers
{
	int level_min;
	int level_max;
	int unknown_1;
	int unknown_2;
	int unknown_3;
	int amount_min;
	int amount_max;
	int quest;
};

public ref struct PQ_Chase
{
	int id_monster;
	int amount_monster;
	float probability;
	int amount_unknown;
};

public ref struct PQ_Item
{
	int ranking_from;
	int ranking_to;
	bool unknown_3;
	int id;
	int amount;
	float probability;
};

public ref struct PQ_Special
{
	int id_pq;
	int unknown_2;
	unsigned char unknown_3;
};

public ref struct PQ_Reward
{
	int chase_count; // public reward chases count
	array<unsigned char>^ unknown_1; // 19 Byte
	int unknown_quest; // New Quest ???
	array<unsigned char>^ unknown_2; // 4 Byte
	int unknown_level; // Level ???
	int contribution_random_min; // random contribution min
	int contribution_random_max; // random contribution max
	int contribution_required; // required reward contribution
	array<unsigned char>^ unknown_3; // 8 Byte
	int item_count; // public reward items count
	array<unsigned char>^ unknown_4; // 4 Byte
	int special_count; // public reward specials count
	array<unsigned char>^ unknown_5; // 29 Byte
	int script_count; // public reward scripts count
	array<unsigned char>^ unknown_6; // 8 Byte
	int message_count; // public reward messages count
	array<unsigned char>^ unknown_7; // 4 Byte

	bool chase_unknown_1;
	int chase_unknown_2;
	bool chase_unknown_3;
	array<PQ_Chase^>^ chases;

	bool item_unknown_1;
	array<PQ_Item^>^ items;

	array<PQ_Special^>^ specials;

	array<array<unsigned char>^>^ scripts; // 576 byte / script

	array<array<unsigned char>^>^ messages; // 128 byte / message
};

public ref struct Reward
{
	int coins;
	int experience;
	int new_quest;
	int spirit;
	int reputation;
	int cultivation;
	int UNKNOWN_1; // 4 Byte
	int storage_slots;
	int cupboard_slots;
	int wardrobe_slots;
	int account_stash_slots;
	int inventory_slots;
	int petbag_slots;
	int vigor;
	Location^ teleport;
	int aiTrigger;
	array<unsigned char>^ UNKNOWN_2a; // 3 Byte
	array<unsigned char>^ UNKNOWN_2b; // 5 Byte
	int item_groups_count;
	array<unsigned char>^ SEPERATOR; // 4 Byte
	PQ_Reward^ pq;
	array<ItemGroup^>^ item_groups;
};

public ref struct PQ_AuditScriptInfo
{
	int id;
	int unknown_1;
	array<unsigned char>^ unknown_2; // 1 Byte
};

public ref struct PQ_AuditScript
{
	array<unsigned char>^ name; // 64 Byte
	int count;
	float id;
	array<unsigned char>^ seperator; // 4 Byte
	float reference_id;
	array<unsigned char>^ code; // 496 Byte
};

public ref struct PQ_AuditChase
{
	int id_monster;
	int amount_1;
	int amount_2;
	int amount_3;
};

public ref struct PQ_AuditExitArea
{
	array<unsigned char>^ unknown_1; // 4 Byte
	LocationSpan^ location;
	/*
	int id_map;
	int location_count;
	array<Span^>^ locations;
	*/
	int unknown_2;
	array<unsigned char>^ unknown_3; // 4 Byte
	int id_script;
	int unknown_4;
	int unknown_5;
	int unknown_6;
	array<unsigned char>^ unknown_7; // 20 Byte
	int script_count;
	array<PQ_AuditScript^>^ scripts;
	array<unsigned char>^ unknown_8; // 4 Byte
	array<unsigned char>^ unknown_9; // 4 Byte
	int message_count;
	array<array<unsigned char>^>^ messages; // 128 byte / message
	array<unsigned char>^ unknown_10; // 4 Byte
};

public ref struct PQ_Audit
{
	int script_info_count; // Unknown Count
	array<PQ_AuditScriptInfo^>^ script_infos;
	array<unsigned char>^ unknown_1; // 12 Byte
	int unknown_2;
	array<unsigned char>^ unknown_3; // 15 Byte
	int script_count; // Scripts Count
	array<PQ_AuditScript^>^ scripts;
	array<unsigned char>^ unknown_4; // 8 Byte
	array<unsigned char>^ unknown_5; // 1 Byte
	array<unsigned char>^ unknown_6; // 1 Byte
	int chase_count;
	array<PQ_AuditChase^>^ chases;
	array<unsigned char>^ unknown_7; // 4 Byte
	array<unsigned char>^ unknown_8; // 5 Byte
	array<unsigned char>^ unknown_9; // 5 Byte
	array<unsigned char>^ unknown_10; // 5 Byte
	PQ_AuditExitArea^ leave_area;
};

public ref struct Answer
{
	int crypt_key;
	int question_link;
	array<unsigned char>^ answer_text;
	// 128 Byte Unicode
	property String^ AnswerText
	{
		String^ get()
		{
			return decrypt(crypt_key, answer_text);
		}
		void set(String^ value)
		{
			answer_text = encrypt(crypt_key, value, 128, false);
		}
	}
	int task_link;
};

public ref struct Question
{
	int crypt_key;
	int question_id;
	int previous_question;
	int question_character_count;
	array<unsigned char>^ question_text;
	// 2*question_character_count Byte Unicode
	property String^ QuestionText
	{
		String^ get()
		{
			return decrypt(crypt_key, question_text);
		}
		void set(String^ value)
		{
			value = value->TrimEnd(gcnew array<wchar_t>{'\0'});
			question_text = encrypt(crypt_key, value, 2*value->Length + 2, true);
			question_character_count = question_text->Length/2;
		}
	}
	int answer_count;
	array<Answer^>^ answers;
};

public ref struct Dialog
{
	int crypt_key;
	int unknown;
	array<unsigned char>^ dialog_text;
	// 128 Byte Unicode
	property String^ DialogText
	{
		String^ get()
		{
			return decrypt(crypt_key, dialog_text);
		}
		void set(String^ value)
		{
			dialog_text = encrypt(crypt_key, value, 128, false);
		}
	}
	int question_count;
	array<Question^>^ questions;
};

public ref struct Conversation
{
	int crypt_key;
	int prompt_character_count;
	array<unsigned char>^ prompt_text;
	// 2*prompt_character_count Byte Unicode
	property String^ PromptText
	{
		String^ get()
		{
			return decrypt(crypt_key, prompt_text);
		}
		void set(String^ value)
		{
			value = value->TrimEnd(gcnew array<wchar_t>{'\0'});
			prompt_text = encrypt(crypt_key, value, 2*value->Length + 2, true);
			prompt_character_count = prompt_text->Length/2;
		}
	}
	array<unsigned char>^ seperator;
	int general_character_count;
	array<unsigned char>^ general_text;
	// 2*general_character_count Byte Unicode
	property String^ GeneralText
	{
		String^ get()
		{
			return decrypt(crypt_key, general_text);
		}
		void set(String^ value)
		{
			value = value->TrimEnd(gcnew array<wchar_t>{'\0'});
			general_text = encrypt(crypt_key, value, 2*value->Length+2, true);
			general_character_count = general_text->Length/2;
		}
	}
	array<Dialog^>^ dialogs;
};

public ref class Task
{
	public: Task(void)
	{
	}
	public: Task(int version, BinaryReader^ BinaryStream, int BaseStreamPosition, TreeNodeCollection^ Nodes)
	{
		Load(version, BinaryStream, BaseStreamPosition, Nodes);
	}	

	protected: ~Task()
	{
	}

	public: int id;
	public: array<unsigned char>^ name;
	// 60 Byte Unicode
	public: property String^ Name
	{
		String^ get()
		{
			return decrypt(id, name);
		}
		void set(String^ value)
		{
			name = encrypt(id, value, 60, false);
		}
	}
	public: bool author_mode;
	public: array<unsigned char>^ UNKNOWN_01; // 4 Byte
	public: int type;
	public: int time_limit;
	public: array<unsigned char>^ UNKNOWN_02; // 1 Byte
	public: bool has_date_fail;
	public: Date^ date_fail;
	public: array<unsigned char>^ UNKNOWN_03; // 1 Byte
	public: bool has_date_spans;
	public: int date_spans_count;
	public: array<unsigned char>^ UNKNOWN_04; // 4 Bytes
	public: array<unsigned char>^ UNKNOWN_05; // 8 Bytes -> All Zeros
	public: array<unsigned char>^ UNKNOWN_06; // 12 Bytes -> All Zeros

	public: array<unsigned char>^ UNKNOWN_07; // 8 Bytes
	public: int UNKNOWN_08; // couple_type
	public: int UNKNOWN_09;
	public: bool activate_first_subquest;
	public: bool activate_random_subquest;
	public: bool activate_next_subquest;
	public: bool on_give_up_parent_fails;
	public: bool on_success_parent_success;
	public: bool can_give_up;
	public: bool repeatable;
	public: bool repeatable_after_failure;
	public: bool fail_on_death;
	public: bool on_fail_parent_fail;
	public: bool UNKNOWN_10;
	public: bool UNKNOWN_11;
	public: bool UNKNOWN_12;
	public: bool UNKNOWN_13;
	public: bool UNKNOWN_14;
	public: bool has_trigger;
	public: LocationSpan^ quest_trigger_locations;
	public: array<unsigned char>^ UNKNOWN_15; // 5 Byte
	public: LocationSpan^ quest_unknown_locations_1;
	public: array<unsigned char>^ UNKNOWN_16; // 5 Byte
	public: LocationSpan^ quest_valid_locations;
	public: array<unsigned char>^ UNKNOWN_17; // 4 Byte
	public: bool has_instant_teleport;
	public: Location^ instant_teleport_location;
	public: int ai_trigger;
	public: bool UNKNOWN_18; // start/stop ai trigger ?
	public: bool UNKNOWN_19;
	public: bool UNKNOWN_20;
	public: bool UNKNOWN_21;
	public: bool UNKNOWN_22; // suicide required ?
	public: bool UNKNOWN_23;
	public: int UNKNOWN_LEVEL;
	public: bool mark_available_icon;
	public: bool mark_available_point;
	public: int quest_npc;
	public: int reward_npc;
	public: bool craft_skill;
	public: bool UNKNOWN_24;
	public: bool UNKNOWN_25;
	public: bool UNKNOWN_26;
	public: PQ_Audit^ pq;
	public: int level_min;
	public: int level_max;
	public: bool UNKNOWN_27; // required items?
	public: int required_items_count;
	public: array<unsigned char>^ required_items_unknown;
	public: bool UNKNOWN_28; // given items?
	public: int given_items_count;
	public: int UNKNOWN_29;
	public: int UNKNOWN_30;
	public: array<unsigned char>^ given_items_unknown; // 4 Byte
	public: int instant_pay_coins;
	public: array<unsigned char>^ UNKNOWN_009b; // 1 Byte
	public: int required_reputation;
	public: array<unsigned char>^ UNKNOWN_010; // 5 Byte
	public: int required_quests_done_count;
	public: array<int>^ required_quests_done;
	public: array<unsigned char>^ UNKNOWN_011_1; // 60 Byte
	public: array<unsigned char>^ UNKNOWN_011_1a; // 1 Byte
	public: int UNKNOWN_011_1ab;
	public: array<unsigned char>^ UNKNOWN_011_1ba; // 9 Byte
	public: int UNKNOWN_011_1bb; // int32
	public: array<unsigned char>^ UNKNOWN_011_1bc; // 1 Byte
	public: int required_gender;
	public: array<unsigned char>^ UNKNOWN_011_2; // 1 Byte
	public: int required_occupations_count;
	public: array<int>^ required_occupations;
	public: array<unsigned char>^ UNKNOWN_011_a2; // 5 Byte
	public: array<unsigned char>^ UNKNOWN_011_a3; // 19 Byte
	public: Date^ unknown_date;
	public: array<unsigned char>^ UNKNOWN_011_a4; // 5 Byte
	public: array<unsigned char>^ UNKNOWN_011_b; // 7 Byte -> All Zeros
	public: int required_quests_undone_count;
	public: array<int>^ required_quests_undone;
	// Married, Occupation, Reputation?, ...

	public: int required_blacksmith_level;
	public: int required_tailor_level;
	public: int required_craftsman_level;
	public: int required_apothecary_level;
	public: array<unsigned char>^ TEAM_MEMBER_REQUIREMENT; // 32 Byte
	public: array<unsigned char>^ UNKNOWN_012; // 3 Byte
	public: int required_team_member_groups_count;
	public: array<unsigned char>^ required_team_member_groups_unknown; // 4 Byte
	public: array<unsigned char>^ UNKNOWN_012_a; // 1 Byte

	public: array<unsigned char>^ UNKNOWN_012_a1; // 9 Byte
	public: int resource_pq_audit_id;
	public: int UNKNOWN_012_a2;
	public: int UNKNOWN_012_a3;
	public: int required_pq_contribution;
	public: array<unsigned char>^ UNKNOWN_012_a4; // 20 Byte

	public: array<unsigned char>^ UNKNOWN_012_b; // 8 Byte
	public: int required_chases_count;
	public: array<unsigned char>^ required_chases_unknown; // 4 Byte
	public: int required_get_items_count;
	public: array<unsigned char>^ required_get_items_unknown; // 4 Byte
	public: int required_coins;
	public: array<unsigned char>^ UNKNOWN_015; // 16 Byte
	public: array<unsigned char>^ UNKNOWN_015a; // 12 Byte
	public: LocationSpan^ required_reach_locations;
	public: int required_wait_time;
	public: array<unsigned char>^ UNKNOWN_016_b; // 8 Byte
	public: array<unsigned char>^ UNKNOWN_016_c; // 24 Byte
	public: int parent_quest;
	public: int previous_quest;
	public: int next_quest;
	public: int sub_quest_first;
	public: bool UNKNOWN_016_d;
	public: array<unsigned char>^ UNKNOWN_016_e;
	public: array<unsigned char>^ author_text;
	// 60 Byte Unicode
	public: property String^ AuthorText
	{
		String^ get()
		{
			return decrypt(id, author_text);
		}
		void set(String^ value)
		{
			author_text = encrypt(id, value, 60, false);
		}
	}
	public: array<DateSpan^>^ date_spans;
	public: array<Item^>^ required_items;
	public: array<Item^>^ given_items;
	public: array<TeamMembers^>^ required_team_member_groups;
	public: array<Chase^>^ required_chases;
	public: array<Item^>^ required_get_items;
	public: Reward^ reward_success;
	public: Reward^ reward_failed;
	public: int rewards_timed_count;
	public: array<float>^ rewards_timed_factors;
	public: array<Reward^>^ rewards_timed;

// Another Rewards section?
	public: array<unsigned char>^ UNKNOWN_025; // 80 Byte //public: Reward^ REWARD_UNKNOWN;
	
	Conversation^ conversation;
	int sub_quest_count;
	array<Task^>^ sub_quests;

	private: void Load(int version, BinaryReader^ br, int stream_position, TreeNodeCollection^ nodes);
	public: void Save(int version, BinaryWriter^ bw);
	public: Task^ Clone();
};