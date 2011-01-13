#pragma once

#include "..\pwAPI\include\pw.h"

using namespace System;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Runtime::InteropServices;
using namespace System::Diagnostics;

array<unsigned char>^ getBytesGBK(String^ Value)
{
	Encoding^ enc = Encoding::GetEncoding("GBK");
	array<unsigned char>^ target = gcnew array<unsigned char>(128);
	array<unsigned char>^ source = enc->GetBytes(Value);
	if(target->Length > source->Length)
	{
		Array::Copy(source, target, source->Length);
	}
	else
	{
		Array::Copy(source, target, target->Length);
	}
	return target;
}

public ref class MainWindow : public System::Windows::Forms::Form
{
	public:
	MainWindow(void)
	{
		InitializeComponent();
		initilaize();
		this->Icon = (Drawing::Icon^)((gcnew Resources::ResourceManager("sTools.icons", Reflection::Assembly::GetExecutingAssembly()))->GetObject("app"));
	}

	protected:
	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	~MainWindow()
	{
		if (components)
		{
			delete components;
		}
	}

	SortedList^ npcDB;
	PW::Data::NpcGen::NpcGen^ npcgen;
	PW::Client::ElementClient^ ecInterface;

	private: System::Windows::Forms::Button^  button_search;
	private: System::Windows::Forms::TextBox^  textBox_search;
	private: System::Windows::Forms::ProgressBar^  progressBar_progress;
	private: System::Windows::Forms::MenuStrip^  menuStrip_mainMenu;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::LinkLabel^  linkLabel_home;
	private: System::Windows::Forms::DataGridView^  dataGridView_creatures;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage_creatures;
	private: System::Windows::Forms::TabPage^  tabPage_resources;
	private: System::Windows::Forms::TabPage^  tabPage_Dynamics;
	private: System::Windows::Forms::TabPage^  tabPage_Triggers;
	private: System::Windows::Forms::DataGridView^  dataGridView_creatureGroups;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_dataGrid;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem4;
	private: System::Windows::Forms::DataGridView^  dataGridView_resourceGroups;
	private: System::Windows::Forms::DataGridView^  dataGridView_resources;
	private: System::Windows::Forms::DataGridView^  dataGridView_Dynamics;
	private: System::Windows::Forms::DataGridView^  dataGridView_Triggers;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn30;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn31;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn32;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn33;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn34;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::GroupBox^  groupBox6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewButtonColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewTextBoxColumn10;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewTextBoxColumn11;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewTextBoxColumn12;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewCheckBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewCheckBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewCheckBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn13;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn14;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewButtonColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn16;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn17;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn18;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn22;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn24;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewCheckBoxColumn4;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewCheckBoxColumn5;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewCheckBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn26;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column27;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column28;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column29;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn27;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn28;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewTextBoxColumn29;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column21;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column22;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewButtonColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn15;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn19;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn20;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn21;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn23;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column24;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column25;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column26;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn25;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewButtonColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn35;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewTextBoxColumn36;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn37;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column23;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewTextBoxColumn38;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  dataGridViewTextBoxColumn39;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn40;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn41;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column42;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn43;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewComboBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn44;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewCheckBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewCheckBoxColumn8;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column43;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn45;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn46;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn47;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn48;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
	private: System::Windows::Forms::DataGridViewComboBoxColumn^  Column12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column13;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column14;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column15;
	private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Column16;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column17;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column18;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column19;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column20;
	private: System::Windows::Forms::ComboBox^  comboBox_AssistantClient;
	private: System::Windows::Forms::Button^  button_AsistantGetValues;
	private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle11 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle12 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle9 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle10 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle13 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle15 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle14 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle21 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle28 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle29 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle22 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle23 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle24 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle25 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle26 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle27 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle30 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle35 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle36 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle31 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle32 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle33 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle34 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle37 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle41 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle42 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle38 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle39 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle40 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		this->button_search = (gcnew System::Windows::Forms::Button());
		this->textBox_search = (gcnew System::Windows::Forms::TextBox());
		this->progressBar_progress = (gcnew System::Windows::Forms::ProgressBar());
		this->menuStrip_mainMenu = (gcnew System::Windows::Forms::MenuStrip());
		this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->loadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->linkLabel_home = (gcnew System::Windows::Forms::LinkLabel());
		this->dataGridView_creatures = (gcnew System::Windows::Forms::DataGridView());
		this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column1 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
		this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column12 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
		this->Column13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column14 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->Column15 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->Column16 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->Column17 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column18 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column19 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column20 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->contextMenuStrip_dataGrid = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
		this->tabPage_creatures = (gcnew System::Windows::Forms::TabPage());
		this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
		this->dataGridView_creatureGroups = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewButtonColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewTextBoxColumn11 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewTextBoxColumn12 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewCheckBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewCheckBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewCheckBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
		this->tabPage_resources = (gcnew System::Windows::Forms::TabPage());
		this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
		this->dataGridView_resourceGroups = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn30 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn31 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn32 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn33 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn34 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
		this->dataGridView_resources = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewButtonColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn17 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn18 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn22 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn24 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewCheckBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewCheckBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewCheckBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewTextBoxColumn26 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column27 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column28 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column29 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn27 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn28 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn29 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->Column21 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->Column22 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->tabPage_Dynamics = (gcnew System::Windows::Forms::TabPage());
		this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
		this->dataGridView_Dynamics = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewButtonColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn19 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn20 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn21 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn23 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column24 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column25 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column26 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->tabPage_Triggers = (gcnew System::Windows::Forms::TabPage());
		this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
		this->dataGridView_Triggers = (gcnew System::Windows::Forms::DataGridView());
		this->dataGridViewTextBoxColumn25 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewButtonColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn35 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn36 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewTextBoxColumn37 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column23 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn38 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewTextBoxColumn39 = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->dataGridViewTextBoxColumn40 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn41 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column42 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
		this->dataGridViewTextBoxColumn43 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewComboBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn44 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewCheckBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewCheckBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Column43 = (gcnew System::Windows::Forms::DataGridViewComboBoxColumn());
		this->dataGridViewTextBoxColumn45 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn46 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn47 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->dataGridViewTextBoxColumn48 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->comboBox_AssistantClient = (gcnew System::Windows::Forms::ComboBox());
		this->button_AsistantGetValues = (gcnew System::Windows::Forms::Button());
		this->menuStrip_mainMenu->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_creatures))->BeginInit();
		this->contextMenuStrip_dataGrid->SuspendLayout();
		this->tabControl1->SuspendLayout();
		this->tabPage_creatures->SuspendLayout();
		this->groupBox2->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_creatureGroups))->BeginInit();
		this->groupBox1->SuspendLayout();
		this->tabPage_resources->SuspendLayout();
		this->groupBox4->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_resourceGroups))->BeginInit();
		this->groupBox3->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_resources))->BeginInit();
		this->tabPage_Dynamics->SuspendLayout();
		this->groupBox5->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Dynamics))->BeginInit();
		this->tabPage_Triggers->SuspendLayout();
		this->groupBox6->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Triggers))->BeginInit();
		this->SuspendLayout();
		// 
		// button_search
		// 
		this->button_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->button_search->Location = System::Drawing::Point(4, 525);
		this->button_search->Name = L"button_search";
		this->button_search->Size = System::Drawing::Size(95, 23);
		this->button_search->TabIndex = 5;
		this->button_search->Text = L"Find Next";
		this->button_search->UseVisualStyleBackColor = true;
		this->button_search->Click += gcnew System::EventHandler(this, &MainWindow::click_search);
		// 
		// textBox_search
		// 
		this->textBox_search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
		this->textBox_search->Location = System::Drawing::Point(105, 527);
		this->textBox_search->Name = L"textBox_search";
		this->textBox_search->Size = System::Drawing::Size(87, 20);
		this->textBox_search->TabIndex = 4;
		this->textBox_search->Text = L"ID";
		this->textBox_search->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// progressBar_progress
		// 
		this->progressBar_progress->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->progressBar_progress->Location = System::Drawing::Point(4, 554);
		this->progressBar_progress->Name = L"progressBar_progress";
		this->progressBar_progress->Size = System::Drawing::Size(784, 16);
		this->progressBar_progress->TabIndex = 9;
		// 
		// menuStrip_mainMenu
		// 
		this->menuStrip_mainMenu->BackColor = System::Drawing::SystemColors::Control;
		this->menuStrip_mainMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripMenuItem1});
		this->menuStrip_mainMenu->Location = System::Drawing::Point(0, 0);
		this->menuStrip_mainMenu->Name = L"menuStrip_mainMenu";
		this->menuStrip_mainMenu->Padding = System::Windows::Forms::Padding(0, 2, 2, 2);
		this->menuStrip_mainMenu->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->menuStrip_mainMenu->Size = System::Drawing::Size(792, 24);
		this->menuStrip_mainMenu->TabIndex = 0;
		this->menuStrip_mainMenu->Text = L"menuStrip1";
		// 
		// toolStripMenuItem1
		// 
		this->toolStripMenuItem1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->loadToolStripMenuItem, 
			this->saveToolStripMenuItem});
		this->toolStripMenuItem1->ImageScaling = System::Windows::Forms::ToolStripItemImageScaling::None;
		this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
		this->toolStripMenuItem1->Padding = System::Windows::Forms::Padding(0);
		this->toolStripMenuItem1->Size = System::Drawing::Size(27, 20);
		this->toolStripMenuItem1->Text = L"File";
		this->toolStripMenuItem1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		// 
		// loadToolStripMenuItem
		// 
		this->loadToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->loadToolStripMenuItem->Name = L"loadToolStripMenuItem";
		this->loadToolStripMenuItem->Size = System::Drawing::Size(110, 22);
		this->loadToolStripMenuItem->Text = L"Load...";
		this->loadToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->loadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_load);
		// 
		// saveToolStripMenuItem
		// 
		this->saveToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
		this->saveToolStripMenuItem->Size = System::Drawing::Size(110, 22);
		this->saveToolStripMenuItem->Text = L"Save...";
		this->saveToolStripMenuItem->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainWindow::click_save);
		// 
		// linkLabel_home
		// 
		this->linkLabel_home->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->linkLabel_home->AutoSize = true;
		this->linkLabel_home->LinkColor = System::Drawing::Color::Blue;
		this->linkLabel_home->Location = System::Drawing::Point(660, 5);
		this->linkLabel_home->Name = L"linkLabel_home";
		this->linkLabel_home->Size = System::Drawing::Size(129, 13);
		this->linkLabel_home->TabIndex = 0;
		this->linkLabel_home->TabStop = true;
		this->linkLabel_home->Text = L"Check Project Homepage";
		this->linkLabel_home->VisitedLinkColor = System::Drawing::Color::Blue;
		this->linkLabel_home->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainWindow::click_home);
		// 
		// dataGridView_creatures
		// 
		this->dataGridView_creatures->AllowUserToAddRows = false;
		this->dataGridView_creatures->AllowUserToDeleteRows = false;
		this->dataGridView_creatures->AllowUserToResizeRows = false;
		this->dataGridView_creatures->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_creatures->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
		dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridView_creatures->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
		this->dataGridView_creatures->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_creatures->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(20) {this->Column2, 
			this->Column1, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8, this->Column9, this->Column10, 
			this->Column11, this->Column12, this->Column13, this->Column14, this->Column15, this->Column16, this->Column17, this->Column18, 
			this->Column19, this->Column20});
		this->dataGridView_creatures->ContextMenuStrip = this->contextMenuStrip_dataGrid;
		dataGridViewCellStyle11->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle11->BackColor = System::Drawing::SystemColors::Window;
		dataGridViewCellStyle11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle11->ForeColor = System::Drawing::SystemColors::ControlText;
		dataGridViewCellStyle11->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle11->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle11->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_creatures->DefaultCellStyle = dataGridViewCellStyle11;
		this->dataGridView_creatures->EnableHeadersVisualStyles = false;
		this->dataGridView_creatures->Location = System::Drawing::Point(6, 19);
		this->dataGridView_creatures->MultiSelect = false;
		this->dataGridView_creatures->Name = L"dataGridView_creatures";
		dataGridViewCellStyle12->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle12->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle12->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle12->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle12->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle12->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridView_creatures->RowHeadersDefaultCellStyle = dataGridViewCellStyle12;
		this->dataGridView_creatures->RowHeadersWidth = 240;
		this->dataGridView_creatures->RowTemplate->Height = 18;
		this->dataGridView_creatures->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
		this->dataGridView_creatures->ShowCellToolTips = false;
		this->dataGridView_creatures->Size = System::Drawing::Size(772, 298);
		this->dataGridView_creatures->TabIndex = 10;
		this->dataGridView_creatures->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_creatures);
		this->dataGridView_creatures->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::click_rowCreature);
		// 
		// Column2
		// 
		this->Column2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle2->Format = L"N3";
		dataGridViewCellStyle2->NullValue = L"0";
		this->Column2->DefaultCellStyle = dataGridViewCellStyle2;
		this->Column2->HeaderText = L"Creature Groups";
		this->Column2->Name = L"Column2";
		this->Column2->ReadOnly = true;
		this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column2->Width = 95;
		// 
		// Column1
		// 
		this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column1->HeaderText = L"Spawn Mode";
		this->Column1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Ground", L"Free 3D"});
		this->Column1->Name = L"Column1";
		this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column1->Width = 78;
		// 
		// Column3
		// 
		this->Column3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle3->Format = L"N3";
		dataGridViewCellStyle3->NullValue = L"0";
		this->Column3->DefaultCellStyle = dataGridViewCellStyle3;
		this->Column3->HeaderText = L"Spawn X";
		this->Column3->Name = L"Column3";
		this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column3->Width = 57;
		// 
		// Column4
		// 
		this->Column4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle4->Format = L"N3";
		dataGridViewCellStyle4->NullValue = L"0";
		this->Column4->DefaultCellStyle = dataGridViewCellStyle4;
		this->Column4->HeaderText = L"Spawn Y";
		this->Column4->Name = L"Column4";
		this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column4->Width = 57;
		// 
		// Column5
		// 
		this->Column5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle5->Format = L"N3";
		dataGridViewCellStyle5->NullValue = L"0";
		this->Column5->DefaultCellStyle = dataGridViewCellStyle5;
		this->Column5->HeaderText = L"Spawn Z";
		this->Column5->Name = L"Column5";
		this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column5->Width = 57;
		// 
		// Column6
		// 
		this->Column6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle6->Format = L"N3";
		dataGridViewCellStyle6->NullValue = nullptr;
		this->Column6->DefaultCellStyle = dataGridViewCellStyle6;
		this->Column6->HeaderText = L"Dir X";
		this->Column6->Name = L"Column6";
		this->Column6->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column6->Width = 45;
		// 
		// Column7
		// 
		this->Column7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column7->HeaderText = L"Dir Y";
		this->Column7->Name = L"Column7";
		this->Column7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column7->Width = 45;
		// 
		// Column8
		// 
		this->Column8->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle7->Format = L"N3";
		dataGridViewCellStyle7->NullValue = nullptr;
		this->Column8->DefaultCellStyle = dataGridViewCellStyle7;
		this->Column8->HeaderText = L"Dir Z";
		this->Column8->Name = L"Column8";
		this->Column8->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column8->Width = 45;
		// 
		// Column9
		// 
		this->Column9->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle8->Format = L"N3";
		dataGridViewCellStyle8->NullValue = nullptr;
		this->Column9->DefaultCellStyle = dataGridViewCellStyle8;
		this->Column9->HeaderText = L"Spread X";
		this->Column9->Name = L"Column9";
		this->Column9->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column9->Width = 59;
		// 
		// Column10
		// 
		this->Column10->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle9->Format = L"N3";
		dataGridViewCellStyle9->NullValue = nullptr;
		this->Column10->DefaultCellStyle = dataGridViewCellStyle9;
		this->Column10->HeaderText = L"Spread Y";
		this->Column10->Name = L"Column10";
		this->Column10->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column10->Width = 59;
		// 
		// Column11
		// 
		this->Column11->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle10->Format = L"N3";
		dataGridViewCellStyle10->NullValue = nullptr;
		this->Column11->DefaultCellStyle = dataGridViewCellStyle10;
		this->Column11->HeaderText = L"Spread Z";
		this->Column11->Name = L"Column11";
		this->Column11->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column11->Width = 59;
		// 
		// Column12
		// 
		this->Column12->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column12->DisplayStyle = System::Windows::Forms::DataGridViewComboBoxDisplayStyle::ComboBox;
		this->Column12->HeaderText = L"Type";
		this->Column12->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Mob", L"NPC"});
		this->Column12->Name = L"Column12";
		this->Column12->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column12->Width = 70;
		// 
		// Column13
		// 
		this->Column13->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column13->HeaderText = L"\?";
		this->Column13->Name = L"Column13";
		this->Column13->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column13->Width = 20;
		// 
		// Column14
		// 
		this->Column14->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column14->HeaderText = L"\?";
		this->Column14->Name = L"Column14";
		this->Column14->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column14->Width = 20;
		// 
		// Column15
		// 
		this->Column15->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column15->HeaderText = L"\?";
		this->Column15->Name = L"Column15";
		this->Column15->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column15->Width = 20;
		// 
		// Column16
		// 
		this->Column16->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column16->HeaderText = L"Instant Respawn";
		this->Column16->Name = L"Column16";
		this->Column16->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column16->Width = 84;
		// 
		// Column17
		// 
		this->Column17->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column17->HeaderText = L"\?";
		this->Column17->Name = L"Column17";
		this->Column17->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column17->Width = 20;
		// 
		// Column18
		// 
		this->Column18->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column18->HeaderText = L"Trigger Link";
		this->Column18->Name = L"Column18";
		this->Column18->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column18->Width = 70;
		// 
		// Column19
		// 
		this->Column19->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column19->HeaderText = L"\?";
		this->Column19->Name = L"Column19";
		this->Column19->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column19->Width = 20;
		// 
		// Column20
		// 
		this->Column20->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column20->HeaderText = L"\?";
		this->Column20->Name = L"Column20";
		this->Column20->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column20->Width = 20;
		// 
		// contextMenuStrip_dataGrid
		// 
		this->contextMenuStrip_dataGrid->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->toolStripMenuItem3, 
			this->toolStripMenuItem4});
		this->contextMenuStrip_dataGrid->Name = L"contextMenuStrip_dataGrid";
		this->contextMenuStrip_dataGrid->RenderMode = System::Windows::Forms::ToolStripRenderMode::System;
		this->contextMenuStrip_dataGrid->ShowImageMargin = false;
		this->contextMenuStrip_dataGrid->Size = System::Drawing::Size(105, 48);
		// 
		// toolStripMenuItem3
		// 
		this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
		this->toolStripMenuItem3->Size = System::Drawing::Size(104, 22);
		this->toolStripMenuItem3->Text = L"Add Row";
		this->toolStripMenuItem3->Click += gcnew System::EventHandler(this, &MainWindow::click_addRow);
		// 
		// toolStripMenuItem4
		// 
		this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
		this->toolStripMenuItem4->Size = System::Drawing::Size(104, 22);
		this->toolStripMenuItem4->Text = L"Delete Row";
		this->toolStripMenuItem4->Click += gcnew System::EventHandler(this, &MainWindow::click_deleteRow);
		// 
		// tabControl1
		// 
		this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->tabControl1->Appearance = System::Windows::Forms::TabAppearance::FlatButtons;
		this->tabControl1->Controls->Add(this->tabPage_creatures);
		this->tabControl1->Controls->Add(this->tabPage_resources);
		this->tabControl1->Controls->Add(this->tabPage_Dynamics);
		this->tabControl1->Controls->Add(this->tabPage_Triggers);
		this->tabControl1->Location = System::Drawing::Point(0, 27);
		this->tabControl1->Name = L"tabControl1";
		this->tabControl1->SelectedIndex = 0;
		this->tabControl1->Size = System::Drawing::Size(792, 494);
		this->tabControl1->TabIndex = 11;
		// 
		// tabPage_creatures
		// 
		this->tabPage_creatures->Controls->Add(this->groupBox2);
		this->tabPage_creatures->Controls->Add(this->groupBox1);
		this->tabPage_creatures->Location = System::Drawing::Point(4, 25);
		this->tabPage_creatures->Name = L"tabPage_creatures";
		this->tabPage_creatures->Size = System::Drawing::Size(784, 465);
		this->tabPage_creatures->TabIndex = 0;
		this->tabPage_creatures->Text = L"Creatures";
		this->tabPage_creatures->UseVisualStyleBackColor = true;
		// 
		// groupBox2
		// 
		this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox2->Controls->Add(this->dataGridView_creatureGroups);
		this->groupBox2->Location = System::Drawing::Point(0, 329);
		this->groupBox2->Name = L"groupBox2";
		this->groupBox2->Size = System::Drawing::Size(784, 136);
		this->groupBox2->TabIndex = 13;
		this->groupBox2->TabStop = false;
		this->groupBox2->Text = L"CREATURE GROUPS";
		// 
		// dataGridView_creatureGroups
		// 
		this->dataGridView_creatureGroups->AllowUserToAddRows = false;
		this->dataGridView_creatureGroups->AllowUserToDeleteRows = false;
		this->dataGridView_creatureGroups->AllowUserToResizeRows = false;
		this->dataGridView_creatureGroups->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_creatureGroups->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
		dataGridViewCellStyle13->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle13->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle13->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle13->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle13->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle13->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridView_creatureGroups->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle13;
		this->dataGridView_creatureGroups->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_creatureGroups->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(18) {this->dataGridViewTextBoxColumn1, 
			this->dataGridViewButtonColumn1, this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn4, 
			this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6, this->dataGridViewTextBoxColumn7, this->dataGridViewTextBoxColumn8, 
			this->dataGridViewTextBoxColumn9, this->dataGridViewTextBoxColumn10, this->dataGridViewTextBoxColumn11, this->dataGridViewTextBoxColumn12, 
			this->dataGridViewCheckBoxColumn1, this->dataGridViewCheckBoxColumn2, this->dataGridViewCheckBoxColumn3, this->dataGridViewTextBoxColumn13, 
			this->dataGridViewTextBoxColumn14});
		dataGridViewCellStyle15->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle15->BackColor = System::Drawing::SystemColors::Window;
		dataGridViewCellStyle15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle15->ForeColor = System::Drawing::SystemColors::ControlText;
		dataGridViewCellStyle15->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle15->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle15->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_creatureGroups->DefaultCellStyle = dataGridViewCellStyle15;
		this->dataGridView_creatureGroups->EnableHeadersVisualStyles = false;
		this->dataGridView_creatureGroups->Location = System::Drawing::Point(6, 19);
		this->dataGridView_creatureGroups->Name = L"dataGridView_creatureGroups";
		dataGridViewCellStyle16->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle16->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle16->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle16->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle16->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle16->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridView_creatureGroups->RowHeadersDefaultCellStyle = dataGridViewCellStyle16;
		this->dataGridView_creatureGroups->RowHeadersWidth = 200;
		this->dataGridView_creatureGroups->RowTemplate->Height = 18;
		this->dataGridView_creatureGroups->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
		this->dataGridView_creatureGroups->ShowCellToolTips = false;
		this->dataGridView_creatureGroups->Size = System::Drawing::Size(772, 111);
		this->dataGridView_creatureGroups->TabIndex = 11;
		this->dataGridView_creatureGroups->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_creatureGroups);
		// 
		// dataGridViewTextBoxColumn1
		// 
		this->dataGridViewTextBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn1->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
		this->dataGridViewTextBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn1->Width = 24;
		// 
		// dataGridViewButtonColumn1
		// 
		this->dataGridViewButtonColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle14->BackColor = System::Drawing::Color::White;
		this->dataGridViewButtonColumn1->DefaultCellStyle = dataGridViewCellStyle14;
		this->dataGridViewButtonColumn1->HeaderText = L"Amount";
		this->dataGridViewButtonColumn1->Name = L"dataGridViewButtonColumn1";
		this->dataGridViewButtonColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewButtonColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewButtonColumn1->Width = 49;
		// 
		// dataGridViewTextBoxColumn2
		// 
		this->dataGridViewTextBoxColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn2->HeaderText = L"Respawn";
		this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
		this->dataGridViewTextBoxColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn2->Width = 58;
		// 
		// dataGridViewTextBoxColumn3
		// 
		this->dataGridViewTextBoxColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn3->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
		this->dataGridViewTextBoxColumn3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn3->Width = 19;
		// 
		// dataGridViewTextBoxColumn4
		// 
		this->dataGridViewTextBoxColumn4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn4->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
		this->dataGridViewTextBoxColumn4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn4->Width = 19;
		// 
		// dataGridViewTextBoxColumn5
		// 
		this->dataGridViewTextBoxColumn5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn5->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
		this->dataGridViewTextBoxColumn5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn5->Width = 19;
		// 
		// dataGridViewTextBoxColumn6
		// 
		this->dataGridViewTextBoxColumn6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn6->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
		this->dataGridViewTextBoxColumn6->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn6->Width = 19;
		// 
		// dataGridViewTextBoxColumn7
		// 
		this->dataGridViewTextBoxColumn7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn7->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
		this->dataGridViewTextBoxColumn7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn7->Width = 19;
		// 
		// dataGridViewTextBoxColumn8
		// 
		this->dataGridViewTextBoxColumn8->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn8->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
		this->dataGridViewTextBoxColumn8->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn8->Width = 19;
		// 
		// dataGridViewTextBoxColumn9
		// 
		this->dataGridViewTextBoxColumn9->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn9->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
		this->dataGridViewTextBoxColumn9->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn9->Width = 19;
		// 
		// dataGridViewTextBoxColumn10
		// 
		this->dataGridViewTextBoxColumn10->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn10->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
		this->dataGridViewTextBoxColumn10->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn10->Width = 19;
		// 
		// dataGridViewTextBoxColumn11
		// 
		this->dataGridViewTextBoxColumn11->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn11->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn11->Name = L"dataGridViewTextBoxColumn11";
		this->dataGridViewTextBoxColumn11->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn11->Width = 19;
		// 
		// dataGridViewTextBoxColumn12
		// 
		this->dataGridViewTextBoxColumn12->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn12->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn12->Name = L"dataGridViewTextBoxColumn12";
		this->dataGridViewTextBoxColumn12->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn12->Width = 19;
		// 
		// dataGridViewCheckBoxColumn1
		// 
		this->dataGridViewCheckBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewCheckBoxColumn1->HeaderText = L"\?";
		this->dataGridViewCheckBoxColumn1->Name = L"dataGridViewCheckBoxColumn1";
		this->dataGridViewCheckBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewCheckBoxColumn1->Width = 19;
		// 
		// dataGridViewCheckBoxColumn2
		// 
		this->dataGridViewCheckBoxColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewCheckBoxColumn2->HeaderText = L"Path ID";
		this->dataGridViewCheckBoxColumn2->Name = L"dataGridViewCheckBoxColumn2";
		this->dataGridViewCheckBoxColumn2->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewCheckBoxColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewCheckBoxColumn2->Width = 49;
		// 
		// dataGridViewCheckBoxColumn3
		// 
		this->dataGridViewCheckBoxColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewCheckBoxColumn3->HeaderText = L"\?";
		this->dataGridViewCheckBoxColumn3->Name = L"dataGridViewCheckBoxColumn3";
		this->dataGridViewCheckBoxColumn3->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewCheckBoxColumn3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewCheckBoxColumn3->Width = 19;
		// 
		// dataGridViewTextBoxColumn13
		// 
		this->dataGridViewTextBoxColumn13->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn13->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn13->Name = L"dataGridViewTextBoxColumn13";
		this->dataGridViewTextBoxColumn13->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn13->Width = 19;
		// 
		// dataGridViewTextBoxColumn14
		// 
		this->dataGridViewTextBoxColumn14->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn14->HeaderText = L"Delay \?";
		this->dataGridViewTextBoxColumn14->Name = L"dataGridViewTextBoxColumn14";
		this->dataGridViewTextBoxColumn14->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn14->Width = 49;
		// 
		// groupBox1
		// 
		this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox1->Controls->Add(this->dataGridView_creatures);
		this->groupBox1->Location = System::Drawing::Point(0, 0);
		this->groupBox1->Name = L"groupBox1";
		this->groupBox1->Size = System::Drawing::Size(784, 323);
		this->groupBox1->TabIndex = 12;
		this->groupBox1->TabStop = false;
		this->groupBox1->Text = L"CREATURE ENTRIES";
		// 
		// tabPage_resources
		// 
		this->tabPage_resources->Controls->Add(this->groupBox4);
		this->tabPage_resources->Controls->Add(this->groupBox3);
		this->tabPage_resources->Location = System::Drawing::Point(4, 25);
		this->tabPage_resources->Name = L"tabPage_resources";
		this->tabPage_resources->Size = System::Drawing::Size(784, 465);
		this->tabPage_resources->TabIndex = 1;
		this->tabPage_resources->Text = L"Resources";
		this->tabPage_resources->UseVisualStyleBackColor = true;
		// 
		// groupBox4
		// 
		this->groupBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox4->Controls->Add(this->dataGridView_resourceGroups);
		this->groupBox4->Location = System::Drawing::Point(0, 329);
		this->groupBox4->Name = L"groupBox4";
		this->groupBox4->Size = System::Drawing::Size(784, 136);
		this->groupBox4->TabIndex = 14;
		this->groupBox4->TabStop = false;
		this->groupBox4->Text = L"RESOURCE GROUPS";
		// 
		// dataGridView_resourceGroups
		// 
		this->dataGridView_resourceGroups->AllowUserToAddRows = false;
		this->dataGridView_resourceGroups->AllowUserToDeleteRows = false;
		this->dataGridView_resourceGroups->AllowUserToResizeRows = false;
		this->dataGridView_resourceGroups->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_resourceGroups->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
		dataGridViewCellStyle17->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle17->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle17->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle17->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle17->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle17->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridView_resourceGroups->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle17;
		this->dataGridView_resourceGroups->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_resourceGroups->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {this->dataGridViewTextBoxColumn30, 
			this->dataGridViewTextBoxColumn31, this->dataGridViewTextBoxColumn32, this->dataGridViewTextBoxColumn33, this->dataGridViewTextBoxColumn34});
		dataGridViewCellStyle19->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle19->BackColor = System::Drawing::SystemColors::Window;
		dataGridViewCellStyle19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle19->ForeColor = System::Drawing::SystemColors::ControlText;
		dataGridViewCellStyle19->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle19->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle19->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_resourceGroups->DefaultCellStyle = dataGridViewCellStyle19;
		this->dataGridView_resourceGroups->EnableHeadersVisualStyles = false;
		this->dataGridView_resourceGroups->Location = System::Drawing::Point(6, 19);
		this->dataGridView_resourceGroups->Name = L"dataGridView_resourceGroups";
		dataGridViewCellStyle20->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle20->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle20->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle20->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle20->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle20->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridView_resourceGroups->RowHeadersDefaultCellStyle = dataGridViewCellStyle20;
		this->dataGridView_resourceGroups->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
		this->dataGridView_resourceGroups->RowTemplate->Height = 18;
		this->dataGridView_resourceGroups->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
		this->dataGridView_resourceGroups->ShowCellToolTips = false;
		this->dataGridView_resourceGroups->Size = System::Drawing::Size(772, 111);
		this->dataGridView_resourceGroups->TabIndex = 12;
		this->dataGridView_resourceGroups->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_resourceGroups);
		// 
		// dataGridViewTextBoxColumn30
		// 
		this->dataGridViewTextBoxColumn30->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn30->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn30->Name = L"dataGridViewTextBoxColumn30";
		this->dataGridViewTextBoxColumn30->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn30->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn30->Width = 19;
		// 
		// dataGridViewTextBoxColumn31
		// 
		this->dataGridViewTextBoxColumn31->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		dataGridViewCellStyle18->BackColor = System::Drawing::Color::White;
		this->dataGridViewTextBoxColumn31->DefaultCellStyle = dataGridViewCellStyle18;
		this->dataGridViewTextBoxColumn31->HeaderText = L"ID";
		this->dataGridViewTextBoxColumn31->Name = L"dataGridViewTextBoxColumn31";
		this->dataGridViewTextBoxColumn31->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn31->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn31->Width = 24;
		// 
		// dataGridViewTextBoxColumn32
		// 
		this->dataGridViewTextBoxColumn32->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn32->HeaderText = L"Respawn";
		this->dataGridViewTextBoxColumn32->Name = L"dataGridViewTextBoxColumn32";
		this->dataGridViewTextBoxColumn32->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn32->Width = 58;
		// 
		// dataGridViewTextBoxColumn33
		// 
		this->dataGridViewTextBoxColumn33->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn33->HeaderText = L"Amount";
		this->dataGridViewTextBoxColumn33->Name = L"dataGridViewTextBoxColumn33";
		this->dataGridViewTextBoxColumn33->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn33->Width = 49;
		// 
		// dataGridViewTextBoxColumn34
		// 
		this->dataGridViewTextBoxColumn34->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
		this->dataGridViewTextBoxColumn34->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn34->Name = L"dataGridViewTextBoxColumn34";
		this->dataGridViewTextBoxColumn34->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn34->Width = 19;
		// 
		// groupBox3
		// 
		this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox3->Controls->Add(this->dataGridView_resources);
		this->groupBox3->Location = System::Drawing::Point(0, 0);
		this->groupBox3->Name = L"groupBox3";
		this->groupBox3->Size = System::Drawing::Size(784, 323);
		this->groupBox3->TabIndex = 13;
		this->groupBox3->TabStop = false;
		this->groupBox3->Text = L"RESOURCE ENTRIES";
		// 
		// dataGridView_resources
		// 
		this->dataGridView_resources->AllowUserToAddRows = false;
		this->dataGridView_resources->AllowUserToDeleteRows = false;
		this->dataGridView_resources->AllowUserToResizeRows = false;
		this->dataGridView_resources->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_resources->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
		dataGridViewCellStyle21->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle21->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle21->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle21->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle21->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle21->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridView_resources->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle21;
		this->dataGridView_resources->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_resources->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(18) {this->dataGridViewButtonColumn2, 
			this->dataGridViewTextBoxColumn16, this->dataGridViewTextBoxColumn17, this->dataGridViewTextBoxColumn18, this->dataGridViewTextBoxColumn22, 
			this->dataGridViewTextBoxColumn24, this->dataGridViewCheckBoxColumn4, this->dataGridViewCheckBoxColumn5, this->dataGridViewCheckBoxColumn6, 
			this->dataGridViewTextBoxColumn26, this->Column27, this->Column28, this->Column29, this->dataGridViewTextBoxColumn27, this->dataGridViewTextBoxColumn28, 
			this->dataGridViewTextBoxColumn29, this->Column21, this->Column22});
		this->dataGridView_resources->ContextMenuStrip = this->contextMenuStrip_dataGrid;
		dataGridViewCellStyle28->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle28->BackColor = System::Drawing::SystemColors::Window;
		dataGridViewCellStyle28->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle28->ForeColor = System::Drawing::SystemColors::ControlText;
		dataGridViewCellStyle28->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle28->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle28->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_resources->DefaultCellStyle = dataGridViewCellStyle28;
		this->dataGridView_resources->EnableHeadersVisualStyles = false;
		this->dataGridView_resources->Location = System::Drawing::Point(6, 19);
		this->dataGridView_resources->MultiSelect = false;
		this->dataGridView_resources->Name = L"dataGridView_resources";
		dataGridViewCellStyle29->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle29->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle29->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle29->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle29->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle29->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle29->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridView_resources->RowHeadersDefaultCellStyle = dataGridViewCellStyle29;
		this->dataGridView_resources->RowHeadersWidth = 80;
		this->dataGridView_resources->RowTemplate->Height = 18;
		this->dataGridView_resources->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
		this->dataGridView_resources->ShowCellToolTips = false;
		this->dataGridView_resources->Size = System::Drawing::Size(772, 298);
		this->dataGridView_resources->TabIndex = 11;
		this->dataGridView_resources->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_resources);
		this->dataGridView_resources->RowEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::click_rowResource);
		// 
		// dataGridViewButtonColumn2
		// 
		this->dataGridViewButtonColumn2->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle22->BackColor = System::Drawing::SystemColors::Control;
		this->dataGridViewButtonColumn2->DefaultCellStyle = dataGridViewCellStyle22;
		this->dataGridViewButtonColumn2->HeaderText = L"Resource Groups";
		this->dataGridViewButtonColumn2->Name = L"dataGridViewButtonColumn2";
		this->dataGridViewButtonColumn2->ReadOnly = true;
		this->dataGridViewButtonColumn2->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewButtonColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		// 
		// dataGridViewTextBoxColumn16
		// 
		this->dataGridViewTextBoxColumn16->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle23->Format = L"N3";
		dataGridViewCellStyle23->NullValue = L"0";
		this->dataGridViewTextBoxColumn16->DefaultCellStyle = dataGridViewCellStyle23;
		this->dataGridViewTextBoxColumn16->HeaderText = L"Spawn X";
		this->dataGridViewTextBoxColumn16->Name = L"dataGridViewTextBoxColumn16";
		this->dataGridViewTextBoxColumn16->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn16->Width = 57;
		// 
		// dataGridViewTextBoxColumn17
		// 
		this->dataGridViewTextBoxColumn17->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle24->Format = L"N3";
		dataGridViewCellStyle24->NullValue = L"0";
		this->dataGridViewTextBoxColumn17->DefaultCellStyle = dataGridViewCellStyle24;
		this->dataGridViewTextBoxColumn17->HeaderText = L"Spawn Y";
		this->dataGridViewTextBoxColumn17->Name = L"dataGridViewTextBoxColumn17";
		this->dataGridViewTextBoxColumn17->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn17->Width = 57;
		// 
		// dataGridViewTextBoxColumn18
		// 
		this->dataGridViewTextBoxColumn18->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle25->Format = L"N3";
		dataGridViewCellStyle25->NullValue = L"0";
		this->dataGridViewTextBoxColumn18->DefaultCellStyle = dataGridViewCellStyle25;
		this->dataGridViewTextBoxColumn18->HeaderText = L"Spawn Z";
		this->dataGridViewTextBoxColumn18->Name = L"dataGridViewTextBoxColumn18";
		this->dataGridViewTextBoxColumn18->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn18->Width = 57;
		// 
		// dataGridViewTextBoxColumn22
		// 
		this->dataGridViewTextBoxColumn22->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle26->Format = L"N3";
		dataGridViewCellStyle26->NullValue = nullptr;
		this->dataGridViewTextBoxColumn22->DefaultCellStyle = dataGridViewCellStyle26;
		this->dataGridViewTextBoxColumn22->HeaderText = L"Spread X";
		this->dataGridViewTextBoxColumn22->Name = L"dataGridViewTextBoxColumn22";
		this->dataGridViewTextBoxColumn22->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn22->Width = 59;
		// 
		// dataGridViewTextBoxColumn24
		// 
		this->dataGridViewTextBoxColumn24->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle27->Format = L"N3";
		dataGridViewCellStyle27->NullValue = nullptr;
		this->dataGridViewTextBoxColumn24->DefaultCellStyle = dataGridViewCellStyle27;
		this->dataGridViewTextBoxColumn24->HeaderText = L"Spread Z";
		this->dataGridViewTextBoxColumn24->Name = L"dataGridViewTextBoxColumn24";
		this->dataGridViewTextBoxColumn24->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn24->Width = 59;
		// 
		// dataGridViewCheckBoxColumn4
		// 
		this->dataGridViewCheckBoxColumn4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewCheckBoxColumn4->HeaderText = L"\?";
		this->dataGridViewCheckBoxColumn4->Name = L"dataGridViewCheckBoxColumn4";
		this->dataGridViewCheckBoxColumn4->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewCheckBoxColumn4->Width = 20;
		// 
		// dataGridViewCheckBoxColumn5
		// 
		this->dataGridViewCheckBoxColumn5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewCheckBoxColumn5->HeaderText = L"\?";
		this->dataGridViewCheckBoxColumn5->Name = L"dataGridViewCheckBoxColumn5";
		this->dataGridViewCheckBoxColumn5->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewCheckBoxColumn5->Width = 20;
		// 
		// dataGridViewCheckBoxColumn6
		// 
		this->dataGridViewCheckBoxColumn6->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewCheckBoxColumn6->HeaderText = L"\?";
		this->dataGridViewCheckBoxColumn6->Name = L"dataGridViewCheckBoxColumn6";
		this->dataGridViewCheckBoxColumn6->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewCheckBoxColumn6->Width = 20;
		// 
		// dataGridViewTextBoxColumn26
		// 
		this->dataGridViewTextBoxColumn26->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn26->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn26->Name = L"dataGridViewTextBoxColumn26";
		this->dataGridViewTextBoxColumn26->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn26->Width = 20;
		// 
		// Column27
		// 
		this->Column27->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column27->HeaderText = L"\?";
		this->Column27->Name = L"Column27";
		this->Column27->Width = 20;
		// 
		// Column28
		// 
		this->Column28->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column28->HeaderText = L"\?";
		this->Column28->Name = L"Column28";
		this->Column28->Width = 20;
		// 
		// Column29
		// 
		this->Column29->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column29->HeaderText = L"\?";
		this->Column29->Name = L"Column29";
		this->Column29->Width = 20;
		// 
		// dataGridViewTextBoxColumn27
		// 
		this->dataGridViewTextBoxColumn27->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn27->HeaderText = L"Trigger Link";
		this->dataGridViewTextBoxColumn27->Name = L"dataGridViewTextBoxColumn27";
		this->dataGridViewTextBoxColumn27->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn27->Width = 70;
		// 
		// dataGridViewTextBoxColumn28
		// 
		this->dataGridViewTextBoxColumn28->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn28->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn28->Name = L"dataGridViewTextBoxColumn28";
		this->dataGridViewTextBoxColumn28->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn28->Width = 20;
		// 
		// dataGridViewTextBoxColumn29
		// 
		this->dataGridViewTextBoxColumn29->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn29->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn29->Name = L"dataGridViewTextBoxColumn29";
		this->dataGridViewTextBoxColumn29->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn29->Width = 20;
		// 
		// Column21
		// 
		this->Column21->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column21->HeaderText = L"\?";
		this->Column21->Name = L"Column21";
		this->Column21->Width = 20;
		// 
		// Column22
		// 
		this->Column22->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column22->HeaderText = L"\?";
		this->Column22->Name = L"Column22";
		this->Column22->Width = 20;
		// 
		// tabPage_Dynamics
		// 
		this->tabPage_Dynamics->Controls->Add(this->groupBox5);
		this->tabPage_Dynamics->Location = System::Drawing::Point(4, 25);
		this->tabPage_Dynamics->Name = L"tabPage_Dynamics";
		this->tabPage_Dynamics->Size = System::Drawing::Size(784, 465);
		this->tabPage_Dynamics->TabIndex = 2;
		this->tabPage_Dynamics->Text = L"Dynamics";
		this->tabPage_Dynamics->UseVisualStyleBackColor = true;
		// 
		// groupBox5
		// 
		this->groupBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox5->Controls->Add(this->dataGridView_Dynamics);
		this->groupBox5->Location = System::Drawing::Point(0, 0);
		this->groupBox5->Name = L"groupBox5";
		this->groupBox5->Size = System::Drawing::Size(784, 465);
		this->groupBox5->TabIndex = 13;
		this->groupBox5->TabStop = false;
		this->groupBox5->Text = L"DYNAMIC ENTRIES";
		// 
		// dataGridView_Dynamics
		// 
		this->dataGridView_Dynamics->AllowUserToAddRows = false;
		this->dataGridView_Dynamics->AllowUserToDeleteRows = false;
		this->dataGridView_Dynamics->AllowUserToResizeRows = false;
		this->dataGridView_Dynamics->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_Dynamics->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
		dataGridViewCellStyle30->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle30->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle30->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle30->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle30->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		this->dataGridView_Dynamics->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle30;
		this->dataGridView_Dynamics->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_Dynamics->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {this->dataGridViewButtonColumn3, 
			this->dataGridViewTextBoxColumn15, this->dataGridViewTextBoxColumn19, this->dataGridViewTextBoxColumn20, this->dataGridViewTextBoxColumn21, 
			this->dataGridViewTextBoxColumn23, this->Column24, this->Column25, this->Column26});
		this->dataGridView_Dynamics->ContextMenuStrip = this->contextMenuStrip_dataGrid;
		dataGridViewCellStyle35->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle35->BackColor = System::Drawing::SystemColors::Window;
		dataGridViewCellStyle35->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle35->ForeColor = System::Drawing::SystemColors::ControlText;
		dataGridViewCellStyle35->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle35->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle35->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_Dynamics->DefaultCellStyle = dataGridViewCellStyle35;
		this->dataGridView_Dynamics->EnableHeadersVisualStyles = false;
		this->dataGridView_Dynamics->Location = System::Drawing::Point(6, 19);
		this->dataGridView_Dynamics->MultiSelect = false;
		this->dataGridView_Dynamics->Name = L"dataGridView_Dynamics";
		dataGridViewCellStyle36->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle36->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle36->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle36->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle36->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle36->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle36->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridView_Dynamics->RowHeadersDefaultCellStyle = dataGridViewCellStyle36;
		this->dataGridView_Dynamics->RowHeadersWidth = 80;
		this->dataGridView_Dynamics->RowTemplate->Height = 18;
		this->dataGridView_Dynamics->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
		this->dataGridView_Dynamics->ShowCellToolTips = false;
		this->dataGridView_Dynamics->Size = System::Drawing::Size(772, 440);
		this->dataGridView_Dynamics->TabIndex = 12;
		this->dataGridView_Dynamics->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_Dynamics);
		// 
		// dataGridViewButtonColumn3
		// 
		this->dataGridViewButtonColumn3->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle31->BackColor = System::Drawing::Color::White;
		this->dataGridViewButtonColumn3->DefaultCellStyle = dataGridViewCellStyle31;
		this->dataGridViewButtonColumn3->HeaderText = L"ID \?";
		this->dataGridViewButtonColumn3->Name = L"dataGridViewButtonColumn3";
		this->dataGridViewButtonColumn3->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewButtonColumn3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewButtonColumn3->Width = 37;
		// 
		// dataGridViewTextBoxColumn15
		// 
		this->dataGridViewTextBoxColumn15->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle32->Format = L"N3";
		dataGridViewCellStyle32->NullValue = L"0";
		this->dataGridViewTextBoxColumn15->DefaultCellStyle = dataGridViewCellStyle32;
		this->dataGridViewTextBoxColumn15->HeaderText = L"Spawn X";
		this->dataGridViewTextBoxColumn15->Name = L"dataGridViewTextBoxColumn15";
		this->dataGridViewTextBoxColumn15->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn15->Width = 63;
		// 
		// dataGridViewTextBoxColumn19
		// 
		this->dataGridViewTextBoxColumn19->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle33->Format = L"N3";
		dataGridViewCellStyle33->NullValue = L"0";
		this->dataGridViewTextBoxColumn19->DefaultCellStyle = dataGridViewCellStyle33;
		this->dataGridViewTextBoxColumn19->HeaderText = L"Spawn Y";
		this->dataGridViewTextBoxColumn19->Name = L"dataGridViewTextBoxColumn19";
		this->dataGridViewTextBoxColumn19->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn19->Width = 63;
		// 
		// dataGridViewTextBoxColumn20
		// 
		this->dataGridViewTextBoxColumn20->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle34->Format = L"N3";
		dataGridViewCellStyle34->NullValue = L"0";
		this->dataGridViewTextBoxColumn20->DefaultCellStyle = dataGridViewCellStyle34;
		this->dataGridViewTextBoxColumn20->HeaderText = L"Spawn Z";
		this->dataGridViewTextBoxColumn20->Name = L"dataGridViewTextBoxColumn20";
		this->dataGridViewTextBoxColumn20->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn20->Width = 63;
		// 
		// dataGridViewTextBoxColumn21
		// 
		this->dataGridViewTextBoxColumn21->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn21->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn21->Name = L"dataGridViewTextBoxColumn21";
		this->dataGridViewTextBoxColumn21->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn21->Width = 20;
		// 
		// dataGridViewTextBoxColumn23
		// 
		this->dataGridViewTextBoxColumn23->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn23->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn23->Name = L"dataGridViewTextBoxColumn23";
		this->dataGridViewTextBoxColumn23->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn23->Width = 20;
		// 
		// Column24
		// 
		this->Column24->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column24->HeaderText = L"\?";
		this->Column24->Name = L"Column24";
		this->Column24->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column24->Width = 20;
		// 
		// Column25
		// 
		this->Column25->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column25->HeaderText = L"Trigger Link";
		this->Column25->Name = L"Column25";
		this->Column25->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column25->Width = 70;
		// 
		// Column26
		// 
		this->Column26->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column26->HeaderText = L"\?";
		this->Column26->Name = L"Column26";
		this->Column26->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column26->Width = 20;
		// 
		// tabPage_Triggers
		// 
		this->tabPage_Triggers->Controls->Add(this->groupBox6);
		this->tabPage_Triggers->Location = System::Drawing::Point(4, 25);
		this->tabPage_Triggers->Name = L"tabPage_Triggers";
		this->tabPage_Triggers->Size = System::Drawing::Size(784, 465);
		this->tabPage_Triggers->TabIndex = 3;
		this->tabPage_Triggers->Text = L"Triggers";
		this->tabPage_Triggers->UseVisualStyleBackColor = true;
		// 
		// groupBox6
		// 
		this->groupBox6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->groupBox6->Controls->Add(this->dataGridView_Triggers);
		this->groupBox6->Location = System::Drawing::Point(0, 0);
		this->groupBox6->Name = L"groupBox6";
		this->groupBox6->Size = System::Drawing::Size(784, 465);
		this->groupBox6->TabIndex = 12;
		this->groupBox6->TabStop = false;
		this->groupBox6->Text = L"TRIGGER ENTRIES";
		// 
		// dataGridView_Triggers
		// 
		this->dataGridView_Triggers->AllowUserToAddRows = false;
		this->dataGridView_Triggers->AllowUserToDeleteRows = false;
		this->dataGridView_Triggers->AllowUserToResizeRows = false;
		this->dataGridView_Triggers->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
			| System::Windows::Forms::AnchorStyles::Left) 
			| System::Windows::Forms::AnchorStyles::Right));
		this->dataGridView_Triggers->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
		dataGridViewCellStyle37->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle37->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle37->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle37->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle37->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle37->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle37->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridView_Triggers->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle37;
		this->dataGridView_Triggers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		this->dataGridView_Triggers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(21) {this->dataGridViewTextBoxColumn25, 
			this->dataGridViewButtonColumn4, this->dataGridViewTextBoxColumn35, this->dataGridViewTextBoxColumn36, this->dataGridViewTextBoxColumn37, 
			this->Column23, this->dataGridViewTextBoxColumn38, this->dataGridViewTextBoxColumn39, this->dataGridViewTextBoxColumn40, this->dataGridViewTextBoxColumn41, 
			this->Column42, this->dataGridViewTextBoxColumn43, this->dataGridViewComboBoxColumn1, this->dataGridViewTextBoxColumn44, this->dataGridViewCheckBoxColumn7, 
			this->dataGridViewCheckBoxColumn8, this->Column43, this->dataGridViewTextBoxColumn45, this->dataGridViewTextBoxColumn46, this->dataGridViewTextBoxColumn47, 
			this->dataGridViewTextBoxColumn48});
		this->dataGridView_Triggers->ContextMenuStrip = this->contextMenuStrip_dataGrid;
		dataGridViewCellStyle41->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle41->BackColor = System::Drawing::SystemColors::Window;
		dataGridViewCellStyle41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle41->ForeColor = System::Drawing::SystemColors::ControlText;
		dataGridViewCellStyle41->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle41->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle41->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
		this->dataGridView_Triggers->DefaultCellStyle = dataGridViewCellStyle41;
		this->dataGridView_Triggers->EnableHeadersVisualStyles = false;
		this->dataGridView_Triggers->Location = System::Drawing::Point(6, 19);
		this->dataGridView_Triggers->MultiSelect = false;
		this->dataGridView_Triggers->Name = L"dataGridView_Triggers";
		dataGridViewCellStyle42->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
		dataGridViewCellStyle42->BackColor = System::Drawing::SystemColors::Control;
		dataGridViewCellStyle42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, 
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		dataGridViewCellStyle42->ForeColor = System::Drawing::SystemColors::WindowText;
		dataGridViewCellStyle42->SelectionBackColor = System::Drawing::SystemColors::Highlight;
		dataGridViewCellStyle42->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
		dataGridViewCellStyle42->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridView_Triggers->RowHeadersDefaultCellStyle = dataGridViewCellStyle42;
		this->dataGridView_Triggers->RowHeadersWidth = 80;
		this->dataGridView_Triggers->RowTemplate->Height = 18;
		this->dataGridView_Triggers->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
		this->dataGridView_Triggers->ShowCellToolTips = false;
		this->dataGridView_Triggers->Size = System::Drawing::Size(772, 440);
		this->dataGridView_Triggers->TabIndex = 11;
		this->dataGridView_Triggers->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_Triggers);
		// 
		// dataGridViewTextBoxColumn25
		// 
		this->dataGridViewTextBoxColumn25->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn25->HeaderText = L"Trigger Link";
		this->dataGridViewTextBoxColumn25->Name = L"dataGridViewTextBoxColumn25";
		this->dataGridViewTextBoxColumn25->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn25->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn25->Width = 72;
		// 
		// dataGridViewButtonColumn4
		// 
		this->dataGridViewButtonColumn4->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle38->BackColor = System::Drawing::Color::White;
		this->dataGridViewButtonColumn4->DefaultCellStyle = dataGridViewCellStyle38;
		this->dataGridViewButtonColumn4->HeaderText = L"Creature Builder ID (GM Activation)";
		this->dataGridViewButtonColumn4->Name = L"dataGridViewButtonColumn4";
		this->dataGridViewButtonColumn4->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewButtonColumn4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewButtonColumn4->Width = 104;
		// 
		// dataGridViewTextBoxColumn35
		// 
		this->dataGridViewTextBoxColumn35->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn35->HeaderText = L"Name";
		this->dataGridViewTextBoxColumn35->Name = L"dataGridViewTextBoxColumn35";
		this->dataGridViewTextBoxColumn35->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn35->Width = 140;
		// 
		// dataGridViewTextBoxColumn36
		// 
		this->dataGridViewTextBoxColumn36->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle39->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle39->Format = L"N3";
		dataGridViewCellStyle39->NullValue = false;
		this->dataGridViewTextBoxColumn36->DefaultCellStyle = dataGridViewCellStyle39;
		this->dataGridViewTextBoxColumn36->HeaderText = L"\?";
		this->dataGridViewTextBoxColumn36->Name = L"dataGridViewTextBoxColumn36";
		this->dataGridViewTextBoxColumn36->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn36->Width = 20;
		// 
		// dataGridViewTextBoxColumn37
		// 
		this->dataGridViewTextBoxColumn37->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn37->HeaderText = L"Delay Auto-Start";
		this->dataGridViewTextBoxColumn37->Name = L"dataGridViewTextBoxColumn37";
		this->dataGridViewTextBoxColumn37->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn37->Width = 81;
		// 
		// Column23
		// 
		this->Column23->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column23->HeaderText = L"Delay Auto-Stop";
		this->Column23->Name = L"Column23";
		this->Column23->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->Column23->Width = 81;
		// 
		// dataGridViewTextBoxColumn38
		// 
		this->dataGridViewTextBoxColumn38->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn38->HeaderText = L"Disable Auto-Start\?";
		this->dataGridViewTextBoxColumn38->Name = L"dataGridViewTextBoxColumn38";
		this->dataGridViewTextBoxColumn38->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn38->Width = 70;
		// 
		// dataGridViewTextBoxColumn39
		// 
		this->dataGridViewTextBoxColumn39->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		dataGridViewCellStyle40->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
		dataGridViewCellStyle40->Format = L"N3";
		dataGridViewCellStyle40->NullValue = false;
		this->dataGridViewTextBoxColumn39->DefaultCellStyle = dataGridViewCellStyle40;
		this->dataGridViewTextBoxColumn39->HeaderText = L"Disable Auto-Stop\?";
		this->dataGridViewTextBoxColumn39->Name = L"dataGridViewTextBoxColumn39";
		this->dataGridViewTextBoxColumn39->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewTextBoxColumn39->Width = 70;
		// 
		// dataGridViewTextBoxColumn40
		// 
		this->dataGridViewTextBoxColumn40->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn40->HeaderText = L"Year 1";
		this->dataGridViewTextBoxColumn40->Name = L"dataGridViewTextBoxColumn40";
		this->dataGridViewTextBoxColumn40->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn40->Width = 50;
		// 
		// dataGridViewTextBoxColumn41
		// 
		this->dataGridViewTextBoxColumn41->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn41->HeaderText = L"Month 1";
		this->dataGridViewTextBoxColumn41->Name = L"dataGridViewTextBoxColumn41";
		this->dataGridViewTextBoxColumn41->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn41->Width = 59;
		// 
		// Column42
		// 
		this->Column42->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column42->HeaderText = L"Week-Day 1";
		this->Column42->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"EVERY", L"Sun", L"Mon", L"Tue", L"Wed", L"Thu", 
			L"Fri", L"Sat"});
		this->Column42->Name = L"Column42";
		this->Column42->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column42->Width = 83;
		// 
		// dataGridViewTextBoxColumn43
		// 
		this->dataGridViewTextBoxColumn43->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn43->HeaderText = L"Day 1";
		this->dataGridViewTextBoxColumn43->Name = L"dataGridViewTextBoxColumn43";
		this->dataGridViewTextBoxColumn43->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn43->Width = 46;
		// 
		// dataGridViewComboBoxColumn1
		// 
		this->dataGridViewComboBoxColumn1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewComboBoxColumn1->HeaderText = L"Hour 1";
		this->dataGridViewComboBoxColumn1->Name = L"dataGridViewComboBoxColumn1";
		this->dataGridViewComboBoxColumn1->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewComboBoxColumn1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewComboBoxColumn1->Width = 45;
		// 
		// dataGridViewTextBoxColumn44
		// 
		this->dataGridViewTextBoxColumn44->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn44->HeaderText = L"Minute 1";
		this->dataGridViewTextBoxColumn44->Name = L"dataGridViewTextBoxColumn44";
		this->dataGridViewTextBoxColumn44->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn44->Width = 54;
		// 
		// dataGridViewCheckBoxColumn7
		// 
		this->dataGridViewCheckBoxColumn7->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewCheckBoxColumn7->HeaderText = L"Year 2";
		this->dataGridViewCheckBoxColumn7->Name = L"dataGridViewCheckBoxColumn7";
		this->dataGridViewCheckBoxColumn7->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewCheckBoxColumn7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewCheckBoxColumn7->Width = 50;
		// 
		// dataGridViewCheckBoxColumn8
		// 
		this->dataGridViewCheckBoxColumn8->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewCheckBoxColumn8->HeaderText = L"Month 2";
		this->dataGridViewCheckBoxColumn8->Name = L"dataGridViewCheckBoxColumn8";
		this->dataGridViewCheckBoxColumn8->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->dataGridViewCheckBoxColumn8->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewCheckBoxColumn8->Width = 59;
		// 
		// Column43
		// 
		this->Column43->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->Column43->HeaderText = L"Week-Day 2";
		this->Column43->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"EVERY", L"Sun", L"Mon", L"Tue", L"Wed", L"Thu", 
			L"Fri", L"Sat"});
		this->Column43->Name = L"Column43";
		this->Column43->Resizable = System::Windows::Forms::DataGridViewTriState::True;
		this->Column43->Width = 83;
		// 
		// dataGridViewTextBoxColumn45
		// 
		this->dataGridViewTextBoxColumn45->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn45->HeaderText = L"Day 2";
		this->dataGridViewTextBoxColumn45->Name = L"dataGridViewTextBoxColumn45";
		this->dataGridViewTextBoxColumn45->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn45->Width = 46;
		// 
		// dataGridViewTextBoxColumn46
		// 
		this->dataGridViewTextBoxColumn46->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn46->HeaderText = L"Hour 2";
		this->dataGridViewTextBoxColumn46->Name = L"dataGridViewTextBoxColumn46";
		this->dataGridViewTextBoxColumn46->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn46->Width = 45;
		// 
		// dataGridViewTextBoxColumn47
		// 
		this->dataGridViewTextBoxColumn47->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn47->HeaderText = L"Minute 2";
		this->dataGridViewTextBoxColumn47->Name = L"dataGridViewTextBoxColumn47";
		this->dataGridViewTextBoxColumn47->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn47->Width = 54;
		// 
		// dataGridViewTextBoxColumn48
		// 
		this->dataGridViewTextBoxColumn48->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
		this->dataGridViewTextBoxColumn48->HeaderText = L"Duration \?";
		this->dataGridViewTextBoxColumn48->Name = L"dataGridViewTextBoxColumn48";
		this->dataGridViewTextBoxColumn48->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
		this->dataGridViewTextBoxColumn48->Width = 62;
		// 
		// comboBox_AssistantClient
		// 
		this->comboBox_AssistantClient->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->comboBox_AssistantClient->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->comboBox_AssistantClient->FormattingEnabled = true;
		this->comboBox_AssistantClient->Location = System::Drawing::Point(554, 527);
		this->comboBox_AssistantClient->Name = L"comboBox_AssistantClient";
		this->comboBox_AssistantClient->Size = System::Drawing::Size(133, 21);
		this->comboBox_AssistantClient->TabIndex = 15;
		// 
		// button_AsistantGetValues
		// 
		this->button_AsistantGetValues->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
		this->button_AsistantGetValues->Location = System::Drawing::Point(693, 525);
		this->button_AsistantGetValues->Name = L"button_AsistantGetValues";
		this->button_AsistantGetValues->Size = System::Drawing::Size(95, 23);
		this->button_AsistantGetValues->TabIndex = 16;
		this->button_AsistantGetValues->Text = L"Get Coordinates";
		this->button_AsistantGetValues->UseVisualStyleBackColor = true;
		this->button_AsistantGetValues->Click += gcnew System::EventHandler(this, &MainWindow::click_getClientValues);
		// 
		// MainWindow
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(792, 573);
		this->Controls->Add(this->tabControl1);
		this->Controls->Add(this->comboBox_AssistantClient);
		this->Controls->Add(this->linkLabel_home);
		this->Controls->Add(this->menuStrip_mainMenu);
		this->Controls->Add(this->button_AsistantGetValues);
		this->Controls->Add(this->progressBar_progress);
		this->Controls->Add(this->button_search);
		this->Controls->Add(this->textBox_search);
		this->MainMenuStrip = this->menuStrip_mainMenu;
		this->MinimumSize = System::Drawing::Size(800, 600);
		this->Name = L"MainWindow";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L" sNPCedit";
		this->menuStrip_mainMenu->ResumeLayout(false);
		this->menuStrip_mainMenu->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_creatures))->EndInit();
		this->contextMenuStrip_dataGrid->ResumeLayout(false);
		this->tabControl1->ResumeLayout(false);
		this->tabPage_creatures->ResumeLayout(false);
		this->groupBox2->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_creatureGroups))->EndInit();
		this->groupBox1->ResumeLayout(false);
		this->tabPage_resources->ResumeLayout(false);
		this->groupBox4->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_resourceGroups))->EndInit();
		this->groupBox3->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_resources))->EndInit();
		this->tabPage_Dynamics->ResumeLayout(false);
		this->groupBox5->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Dynamics))->EndInit();
		this->tabPage_Triggers->ResumeLayout(false);
		this->groupBox6->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView_Triggers))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

	}

#pragma endregion

	void initilaize()
	{
		ecInterface = gcnew PW::Client::ElementClient(Application::StartupPath + "\\sNPCedit\\ec_offset_profiles.txt");

		comboBox_AssistantClient->Items->Clear();
		comboBox_AssistantClient->Items->AddRange(ecInterface->GetProfileNames());
		if(comboBox_AssistantClient->Items->Count > 0)
		{
			comboBox_AssistantClient->SelectedIndex = 0;
		}

		npcDB = gcnew SortedList();

		if(File::Exists(Application::StartupPath + "\\sNPCedit\\npcdb.txt"))
		{
			try
			{
				StreamReader^ sr = gcnew StreamReader(Application::StartupPath + "\\sNPCedit\\npcdb.txt", Encoding::Unicode);

				array<wchar_t>^ seperator = gcnew array<wchar_t>{'\t'};
				String^ line;
				array<String^>^ split;

				while((line = sr->ReadLine()))
				{
					if(line->Contains("\t"))
					{
						split = line->Split(seperator);
						npcDB->Add(split[0], split[1]);
					}
				}

				sr->Close();
			}
			catch(Exception^ e)
			{
				MessageBox::Show("ERROR LOADING NPC DB\n" + e->Message);
			}
		}
	}
	String^ npcName(int id)
	{
		String^ result = (String^)npcDB[id.ToString()];
		if(!result)
		{
			result = "NOT FOUND";
		}

		return result;
	}
	private: System::Void click_load(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ load = gcnew OpenFileDialog();
		load->Filter = "NPCGEN (*.data)|*.data|All Files (*.*)|*.*";
		if(load->ShowDialog() == Windows::Forms::DialogResult::OK && File::Exists(load->FileName))
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Marquee;

				Encoding^ enc = Encoding::GetEncoding("GBK");

				npcgen = gcnew PW::Data::NpcGen::NpcGen();
				npcgen->Load(load->FileName);

				dataGridView_creatures->Rows->Clear();
				for(int i=0; i<npcgen->CreatureSets->Length; i++)
				{
					dataGridView_creatures->Rows->Add(gcnew array<String^>{
						npcgen->CreatureSets[i]->CreatureGroups->Length.ToString(),
						Column1->Items[npcgen->CreatureSets[i]->SpawnMode]->ToString(),
						npcgen->CreatureSets[i]->SpawnX.ToString("F3"),
						npcgen->CreatureSets[i]->SpawnAltitude.ToString("F3"),
						npcgen->CreatureSets[i]->SpawnZ.ToString("F3"),
						npcgen->CreatureSets[i]->DirectionX.ToString("F3"),
						npcgen->CreatureSets[i]->DirectionAltitude.ToString("F3"),
						npcgen->CreatureSets[i]->DirectionZ.ToString("F3"),
						npcgen->CreatureSets[i]->SpreadX.ToString("F3"),
						npcgen->CreatureSets[i]->SpreadAltitude.ToString("F3"),
						npcgen->CreatureSets[i]->SpreadZ.ToString("F3"),
						Column12->Items[npcgen->CreatureSets[i]->Type]->ToString(),
						npcgen->CreatureSets[i]->unknown_8.ToString(),
						npcgen->CreatureSets[i]->unknown_9.ToString(),
						npcgen->CreatureSets[i]->unknown_10.ToString(),
						npcgen->CreatureSets[i]->InstantRespawn.ToString(),
						npcgen->CreatureSets[i]->unknown_12.ToString(),
						npcgen->CreatureSets[i]->TriggerID.ToString(),
						npcgen->CreatureSets[i]->unknown_14.ToString(),
						npcgen->CreatureSets[i]->unknown_15.ToString()
					});

					if(npcgen->CreatureSets[i]->CreatureGroups->Length>0)
					{
						dataGridView_creatures->Rows[i]->HeaderCell->Value = "[" + npcgen->CreatureSets[i]->CreatureGroups[0]->ID.ToString() + "] " + npcName(npcgen->CreatureSets[i]->CreatureGroups[0]->ID);
					}
				}

				dataGridView_resources->Rows->Clear();
				for(int i=0; i<npcgen->ResourceSets->Length; i++)
				{
					Application::DoEvents();

					dataGridView_resources->Rows->Add(gcnew array<String^>{
						npcgen->ResourceSets[i]->ResourceGroups->Length.ToString(),
						npcgen->ResourceSets[i]->SpawnX.ToString("F3"),
						npcgen->ResourceSets[i]->SpawnAltitude.ToString("F3"),
						npcgen->ResourceSets[i]->SpawnZ.ToString("F3"),
						npcgen->ResourceSets[i]->SpreadX.ToString("F3"),
						npcgen->ResourceSets[i]->SpreadZ.ToString("F3"),
						npcgen->ResourceSets[i]->unknown_1.ToString(),
						npcgen->ResourceSets[i]->unknown_2.ToString(),
						npcgen->ResourceSets[i]->unknown_3.ToString(),
						npcgen->ResourceSets[i]->unknown_4.ToString(),
						npcgen->ResourceSets[i]->unknown_5a.ToString(),
						npcgen->ResourceSets[i]->unknown_5b.ToString(),
						npcgen->ResourceSets[i]->unknown_5c.ToString(),
						npcgen->ResourceSets[i]->TriggerID.ToString(),
						npcgen->ResourceSets[i]->unknown_6.ToString(),
						npcgen->ResourceSets[i]->unknown_7.ToString(),
						npcgen->ResourceSets[i]->unknown_8.ToString(),
						npcgen->ResourceSets[i]->unknown_9.ToString()
					});

					if(npcgen->ResourceSets[i]->ResourceGroups->Length>0)
					{
						dataGridView_resources->Rows[i]->HeaderCell->Value = npcgen->ResourceSets[i]->ResourceGroups[0]->ID.ToString();
					}
				}

				dataGridView_Dynamics->Rows->Clear();
				for(int i=0; i<npcgen->Dynamics->Length; i++)
				{
					Application::DoEvents();

					dataGridView_Dynamics->Rows->Add(gcnew array<String^>{
						npcgen->Dynamics[i]->ID.ToString(),
						npcgen->Dynamics[i]->SpawnX.ToString("F3"),
						npcgen->Dynamics[i]->SpawnAltitude.ToString("F3"),
						npcgen->Dynamics[i]->SpawnZ.ToString("F3"),
						npcgen->Dynamics[i]->unknown_5.ToString(),
						npcgen->Dynamics[i]->unknown_6.ToString(),
						npcgen->Dynamics[i]->unknown_7.ToString(),
						npcgen->Dynamics[i]->TriggerID.ToString(),
						npcgen->Dynamics[i]->unknown_8.ToString()
					});

					dataGridView_Dynamics->Rows[i]->HeaderCell->Value = (dataGridView_Dynamics->Rows->Count-1).ToString();
				}

				dataGridView_Triggers->Rows->Clear();
				for(int i=0; i<npcgen->Triggers->Length; i++)
				{
					Application::DoEvents();

					dataGridView_Triggers->Rows->Add(gcnew array<String^>{
						npcgen->Triggers[i]->TriggerID.ToString(),
						npcgen->Triggers[i]->CreatureBuilderID.ToString(),
						enc->GetString(npcgen->Triggers[i]->Name),
						npcgen->Triggers[i]->unknown_3.ToString(),
						npcgen->Triggers[i]->AutostartDelayTime.ToString(),
						npcgen->Triggers[i]->AutostopDelayTime.ToString(),
						npcgen->Triggers[i]->AutostartDisable.ToString(),
						npcgen->Triggers[i]->AutostopDisable.ToString(),
						npcgen->Triggers[i]->StartYear.ToString(),
						npcgen->Triggers[i]->StartMonth.ToString(),
						Column42->Items[npcgen->Triggers[i]->StartWeekDay+1]->ToString(),
						npcgen->Triggers[i]->StartDay.ToString(),
						npcgen->Triggers[i]->StartHour.ToString(),
						npcgen->Triggers[i]->StartMinute.ToString(),
						npcgen->Triggers[i]->EndYear.ToString(),
						npcgen->Triggers[i]->EndMonth.ToString(),
						Column43->Items[npcgen->Triggers[i]->EndWeekDay+1]->ToString(),
						npcgen->Triggers[i]->EndDay.ToString(),
						npcgen->Triggers[i]->EndHour.ToString(),
						npcgen->Triggers[i]->EndMinute.ToString(),
						npcgen->Triggers[i]->Duration.ToString()
					});

					dataGridView_Triggers->Rows[i]->HeaderCell->Value = (dataGridView_Triggers->Rows->Count-1).ToString();
				}

				this->Text = " sNPCedit (" + load->FileName + ")";

				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(Exception^ e)
			{
				MessageBox::Show("LOADING ERROR!\n" + e->Message);
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}

	private: System::Void click_save(System::Object^  sender, System::EventArgs^  e)
	{
		SaveFileDialog^ save = gcnew SaveFileDialog();
		save->InitialDirectory = Environment::CurrentDirectory;
		save->Filter = "Elements File (*.data)|*.data|All Files (*.*)|*.*";
		if(npcgen && save->ShowDialog() == Windows::Forms::DialogResult::OK && save->FileName != "")
		{
			try
			{
				Cursor = Windows::Forms::Cursors::AppStarting;
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Marquee;

				npcgen->Save(save->FileName);

				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
			catch(...)
			{
				MessageBox::Show("SAVING ERROR!");
				progressBar_progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				Cursor = Windows::Forms::Cursors::Default;
			}
		}
	}

	private: System::Void click_home(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^  e)
	{
		Diagnostics::Process::Start("http://snpcedit.codeplex.com");
	}

	private: System::Void click_cellCreature(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		dataGridView_creatureGroups->Rows->Clear();
		dataGridView_creatureGroups->ContextMenuStrip = nullptr;

		if(npcgen && e->RowIndex>-1 && e->ColumnIndex == 0 && e->RowIndex<npcgen->CreatureSets->Length)
		{
			for(int i=0; i<npcgen->CreatureSets[e->RowIndex]->CreatureGroups->Length; i++)
			{
				dataGridView_creatureGroups->Rows->Add(gcnew array<String^>{
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->ID.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->Amount.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->Respawn.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_2.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_3.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_4.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_5.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_6.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_7.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_8.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_9.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_10.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_11.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_12.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->PathID.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_14.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_15.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_16.ToString()
				}
				);
			}
			dataGridView_creatureGroups->ContextMenuStrip = contextMenuStrip_dataGrid;
		}
	}

	private: System::Void click_rowCreature(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		dataGridView_creatureGroups->Rows->Clear();
		dataGridView_creatureGroups->ContextMenuStrip = nullptr;

		if(npcgen && e->RowIndex>-1 && e->RowIndex<npcgen->CreatureSets->Length)
		{
			for(int i=0; i<npcgen->CreatureSets[e->RowIndex]->CreatureGroups->Length; i++)
			{
				dataGridView_creatureGroups->Rows->Add(gcnew array<String^>{
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->ID.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->Amount.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->Respawn.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_2.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_3.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_4.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_5.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_6.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_7.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_8.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_9.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_10.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_11.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_12.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->PathID.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_14.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_15.ToString(),
						npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->unknown_16.ToString()
				}
				);
				this->dataGridView_creatureGroups->CellValueChanged -= gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_creatureGroups);
				dataGridView_creatureGroups->Rows[i]->HeaderCell->Value = npcName(npcgen->CreatureSets[e->RowIndex]->CreatureGroups[i]->ID);
				this->dataGridView_creatureGroups->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainWindow::change_creatureGroups);
			}
			dataGridView_creatureGroups->ContextMenuStrip = contextMenuStrip_dataGrid;
		}
	}

	private: System::Void click_cellResource(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		dataGridView_resourceGroups->Rows->Clear();
		dataGridView_resourceGroups->ContextMenuStrip = nullptr;

		if(npcgen && e->RowIndex>-1 && e->ColumnIndex == 0 && e->RowIndex<npcgen->ResourceSets->Length)
		{
			for(int i=0; i<npcgen->ResourceSets[e->RowIndex]->ResourceGroups->Length; i++)
			{
				dataGridView_resourceGroups->Rows->Add(gcnew array<String^>{
					npcgen->ResourceSets[e->RowIndex]->ResourceGroups[i]->unknown_1.ToString(),
					npcgen->ResourceSets[e->RowIndex]->ResourceGroups[i]->ID.ToString(),
					npcgen->ResourceSets[e->RowIndex]->ResourceGroups[i]->Respawn.ToString(),
					npcgen->ResourceSets[e->RowIndex]->ResourceGroups[i]->Amount.ToString(),
					npcgen->ResourceSets[e->RowIndex]->ResourceGroups[i]->unknown_2.ToString()
				});
			}
			dataGridView_resourceGroups->ContextMenuStrip = contextMenuStrip_dataGrid;
		}
	}
	private: System::Void click_rowResource(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		dataGridView_resourceGroups->Rows->Clear();
		dataGridView_resourceGroups->ContextMenuStrip = nullptr;

		if(npcgen && e->RowIndex>-1 && e->RowIndex<npcgen->ResourceSets->Length)
		{
			for(int i=0; i<npcgen->ResourceSets[e->RowIndex]->ResourceGroups->Length; i++)
			{
				dataGridView_resourceGroups->Rows->Add(gcnew array<String^>{
					npcgen->ResourceSets[e->RowIndex]->ResourceGroups[i]->unknown_1.ToString(),
					npcgen->ResourceSets[e->RowIndex]->ResourceGroups[i]->ID.ToString(),
					npcgen->ResourceSets[e->RowIndex]->ResourceGroups[i]->Respawn.ToString(),
					npcgen->ResourceSets[e->RowIndex]->ResourceGroups[i]->Amount.ToString(),
					npcgen->ResourceSets[e->RowIndex]->ResourceGroups[i]->unknown_2.ToString()
				});
			}
			dataGridView_resourceGroups->ContextMenuStrip = contextMenuStrip_dataGrid;
		}
	}
	private: System::Void click_addRow(System::Object^  sender, System::EventArgs^  e)
	{
		if(npcgen)
		{
			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_creatures)
			{
				Array::Resize(npcgen->CreatureSets, npcgen->CreatureSets->Length+1);
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1] = gcnew PW::Data::NpcGen::CreatureSet();

				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->SpawnMode = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->SpawnX = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->SpawnAltitude = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->SpawnZ = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->DirectionX = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->DirectionAltitude = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->DirectionZ = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->SpreadX = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->SpreadAltitude = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->SpreadZ = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->Type = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->unknown_8 = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->unknown_9 = true;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->unknown_10 = true;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->InstantRespawn = true;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->unknown_12 = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->TriggerID = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->unknown_14 = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->unknown_15 = 0;
				npcgen->CreatureSets[npcgen->CreatureSets->Length-1]->CreatureGroups = gcnew array<PW::Data::NpcGen::CreatureGroup^>(0);

				dataGridView_creatures->Rows->Add("0", Column1->Items[0]->ToString(), "0", "0", "0", "0", "0", "0", "0", "0", "0", Column12->Items[0]->ToString(), "0", "True", "True", "True", "0", "0", "0", "0");
				dataGridView_creatures->Rows[dataGridView_creatures->Rows->Count-1]->HeaderCell->Value = "";
			}

			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_creatureGroups)
			{
				int r = dataGridView_creatures->CurrentCell->RowIndex;

				Array::Resize(npcgen->CreatureSets[r]->CreatureGroups, npcgen->CreatureSets[r]->CreatureGroups->Length+1);
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1] = gcnew PW::Data::NpcGen::CreatureGroup();

				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->ID = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->Amount = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->Respawn = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_2 = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_3 = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_4 = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_5 = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_6 = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_7 = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_8 = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_9 = false;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_10 = true;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_11 = true;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_12 = true;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->PathID = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_14 = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_15 = 0;
				npcgen->CreatureSets[r]->CreatureGroups[npcgen->CreatureSets[r]->CreatureGroups->Length-1]->unknown_16 = 0;

				dataGridView_creatureGroups->Rows->Add("0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "False", "True", "True", "True", "0", "0", "0", "0");
				if(npcgen->CreatureSets[r]->CreatureGroups->Length>0)
				{
					dataGridView_creatures->Rows[r]->HeaderCell->Value = "[" + npcgen->CreatureSets[r]->CreatureGroups[0]->ID.ToString() + "] " + npcName(npcgen->CreatureSets[r]->CreatureGroups[0]->ID);
				}
				else
				{
					dataGridView_creatures->Rows[r]->HeaderCell->Value = "";
				}
				dataGridView_creatures->Rows[r]->Cells[0]->Value = (dataGridView_creatureGroups->Rows->Count).ToString();
			}

			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_resources)
			{
				Array::Resize(npcgen->ResourceSets, npcgen->ResourceSets->Length+1);
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1] = gcnew PW::Data::NpcGen::ResourceSet();

				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->SpawnX = 0;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->SpawnAltitude = 0;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->SpawnZ = 0;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->SpreadX = 0;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->SpreadZ = 0;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->unknown_1 = true;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->unknown_2 = true;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->unknown_3 = true;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->unknown_4 = 0;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->unknown_5a = 192;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->unknown_5b = 63;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->unknown_5c = 0;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->TriggerID = 0;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->unknown_6 = 0;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->unknown_7 = false;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->unknown_8 = false;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->unknown_9 = false;
				npcgen->ResourceSets[npcgen->ResourceSets->Length-1]->ResourceGroups = gcnew array<PW::Data::NpcGen::ResourceGroup^>(0);

				dataGridView_resources->Rows->Add("0", "0", "0", "0", "0", "0", "True", "True", "True", "0", "192", "63", "0", "0", "0", "False", "False", "False");
				dataGridView_resources->Rows[dataGridView_resources->Rows->Count-1]->HeaderCell->Value = "";
			}

			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_resourceGroups)
			{
				int r = dataGridView_resources->CurrentCell->RowIndex;

				Array::Resize(npcgen->ResourceSets[r]->ResourceGroups, npcgen->ResourceSets[r]->ResourceGroups->Length+1);
				npcgen->ResourceSets[r]->ResourceGroups[npcgen->ResourceSets[r]->ResourceGroups->Length-1] = gcnew PW::Data::NpcGen::ResourceGroup();

				npcgen->ResourceSets[r]->ResourceGroups[npcgen->ResourceSets[r]->ResourceGroups->Length-1]->unknown_1 = 0;
				npcgen->ResourceSets[r]->ResourceGroups[npcgen->ResourceSets[r]->ResourceGroups->Length-1]->ID = 0;
				npcgen->ResourceSets[r]->ResourceGroups[npcgen->ResourceSets[r]->ResourceGroups->Length-1]->Respawn = 0;
				npcgen->ResourceSets[r]->ResourceGroups[npcgen->ResourceSets[r]->ResourceGroups->Length-1]->Amount = 0;
				npcgen->ResourceSets[r]->ResourceGroups[npcgen->ResourceSets[r]->ResourceGroups->Length-1]->unknown_2 = 0;

				dataGridView_resourceGroups->Rows->Add("0", "0", "0", "0", "0");
				if(npcgen->ResourceSets[r]->ResourceGroups->Length>0)
				{
					dataGridView_resources->Rows[r]->HeaderCell->Value = npcgen->ResourceSets[r]->ResourceGroups[0]->ID.ToString();
				}
				else
				{
					dataGridView_resources->Rows[r]->HeaderCell->Value = "";
				}
				dataGridView_resources->Rows[r]->Cells[0]->Value = (dataGridView_resourceGroups->Rows->Count).ToString();
			}

			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_Dynamics)
			{
				Array::Resize(npcgen->Dynamics, npcgen->Dynamics->Length+1);
				npcgen->Dynamics[npcgen->Dynamics->Length-1] = gcnew PW::Data::NpcGen::Dynamic();

				npcgen->Dynamics[npcgen->Dynamics->Length-1]->ID = 0;
				npcgen->Dynamics[npcgen->Dynamics->Length-1]->SpawnX = 0;
				npcgen->Dynamics[npcgen->Dynamics->Length-1]->SpawnAltitude = 0;
				npcgen->Dynamics[npcgen->Dynamics->Length-1]->SpawnZ = 0;
				npcgen->Dynamics[npcgen->Dynamics->Length-1]->unknown_5 = 0;
				npcgen->Dynamics[npcgen->Dynamics->Length-1]->unknown_6 = 0;
				npcgen->Dynamics[npcgen->Dynamics->Length-1]->unknown_7 = 0;
				npcgen->Dynamics[npcgen->Dynamics->Length-1]->TriggerID = 0;
				npcgen->Dynamics[npcgen->Dynamics->Length-1]->unknown_8 = 16;

				dataGridView_Dynamics->Rows->Add("0", "0", "0", "0", "0", "0", "0", "0", "16");
				dataGridView_Dynamics->Rows[dataGridView_Dynamics->Rows->Count-1]->HeaderCell->Value = (dataGridView_Dynamics->Rows->Count-1).ToString();
			}

			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_Triggers)
			{
				Array::Resize(npcgen->Triggers, npcgen->Triggers->Length+1);
				npcgen->Triggers[npcgen->Triggers->Length-1] = gcnew PW::Data::NpcGen::Trigger();

				npcgen->Triggers[npcgen->Triggers->Length-1]->TriggerID = 0;
				npcgen->Triggers[npcgen->Triggers->Length-1]->CreatureBuilderID = 0;
				npcgen->Triggers[npcgen->Triggers->Length-1]->Name = gcnew array<unsigned char>(128);
				npcgen->Triggers[npcgen->Triggers->Length-1]->unknown_3 = false;
				npcgen->Triggers[npcgen->Triggers->Length-1]->AutostartDelayTime = 0;
				npcgen->Triggers[npcgen->Triggers->Length-1]->AutostopDelayTime = 0;
				npcgen->Triggers[npcgen->Triggers->Length-1]->AutostartDisable = false;
				npcgen->Triggers[npcgen->Triggers->Length-1]->AutostopDisable = false;
				npcgen->Triggers[npcgen->Triggers->Length-1]->StartYear = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->StartMonth = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->StartWeekDay = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->StartDay = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->StartHour = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->StartMinute = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->EndYear = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->EndMonth = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->EndWeekDay = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->EndDay = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->EndHour = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->EndMinute = -1;
				npcgen->Triggers[npcgen->Triggers->Length-1]->Duration = 0;

				dataGridView_Triggers->Rows->Add("0", "0", "", "False", "0", "0", "False", "False", "-1", "-1", Column42->Items[0]->ToString(), "-1", "-1", "-1", "-1", "-1", Column43->Items[0]->ToString(), "-1", "-1", "-1", "0");
				dataGridView_Triggers->Rows[dataGridView_Triggers->Rows->Count-1]->HeaderCell->Value = (dataGridView_Triggers->Rows->Count-1).ToString();
			}
		}
	}
	private: System::Void click_deleteRow(System::Object^  sender, System::EventArgs^  e)
	{
		if(npcgen)
		{
			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_creatures)
			{
				if(npcgen->CreatureSets->Length>0 && dataGridView_creatures->CurrentCell->RowIndex>-1)
				{
					array<PW::Data::NpcGen::CreatureSet^>^ temp = gcnew array<PW::Data::NpcGen::CreatureSet^>(npcgen->CreatureSets->Length-1);
					Array::Copy(npcgen->CreatureSets, 0, temp, 0, dataGridView_creatures->CurrentCell->RowIndex);
					Array::Copy(npcgen->CreatureSets, dataGridView_creatures->CurrentCell->RowIndex+1, temp, dataGridView_creatures->CurrentCell->RowIndex, temp->Length - dataGridView_creatures->CurrentCell->RowIndex);
					npcgen->CreatureSets = temp;

					dataGridView_creatureGroups->Rows->Clear();
					dataGridView_creatures->Rows->RemoveAt(dataGridView_creatures->CurrentCell->RowIndex);
				}
			}

			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_creatureGroups)
			{
				if(dataGridView_creatures->CurrentCell->RowIndex>-1)
				{
					int r = dataGridView_creatures->CurrentCell->RowIndex;

					if(npcgen->CreatureSets[r]->CreatureGroups->Length>0 && dataGridView_creatureGroups->CurrentCell->RowIndex>-1)
					{
						array<PW::Data::NpcGen::CreatureGroup^>^ temp = gcnew array<PW::Data::NpcGen::CreatureGroup^>(npcgen->CreatureSets[r]->CreatureGroups->Length-1);
						Array::Copy(npcgen->CreatureSets[r]->CreatureGroups, 0, temp, 0, dataGridView_creatureGroups->CurrentCell->RowIndex);
						Array::Copy(npcgen->CreatureSets[r]->CreatureGroups, dataGridView_creatureGroups->CurrentCell->RowIndex+1, temp, dataGridView_creatureGroups->CurrentCell->RowIndex, temp->Length - dataGridView_creatureGroups->CurrentCell->RowIndex);
						npcgen->CreatureSets[r]->CreatureGroups = temp;

						dataGridView_creatureGroups->Rows->RemoveAt(dataGridView_creatureGroups->CurrentCell->RowIndex);
						if(npcgen->CreatureSets[r]->CreatureGroups->Length>0)
						{
							dataGridView_creatures->Rows[r]->HeaderCell->Value = "[" + npcgen->CreatureSets[r]->CreatureGroups[0]->ID.ToString() + "] " + npcName(npcgen->CreatureSets[r]->CreatureGroups[0]->ID);
						}
						else
						{
							dataGridView_creatures->Rows[r]->HeaderCell->Value = "";
						}
						dataGridView_creatures->Rows[r]->Cells[0]->Value = (dataGridView_creatureGroups->Rows->Count).ToString();
					}
				}
			}

			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_resources)
			{
				if(npcgen->ResourceSets->Length>0 && dataGridView_resources->CurrentCell->RowIndex>-1)
				{
					array<PW::Data::NpcGen::ResourceSet^>^ temp = gcnew array<PW::Data::NpcGen::ResourceSet^>(npcgen->ResourceSets->Length-1);
					Array::Copy(npcgen->ResourceSets, 0, temp, 0, dataGridView_resources->CurrentCell->RowIndex);
					Array::Copy(npcgen->ResourceSets, dataGridView_resources->CurrentCell->RowIndex+1, temp, dataGridView_resources->CurrentCell->RowIndex, temp->Length - dataGridView_resources->CurrentCell->RowIndex);
					npcgen->ResourceSets = temp;

					dataGridView_resourceGroups->Rows->Clear();
					dataGridView_resources->Rows->RemoveAt(dataGridView_resources->CurrentCell->RowIndex);
				}
			}

			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_resourceGroups)
			{
				if(dataGridView_resources->CurrentCell->RowIndex>-1)
				{
					int r = dataGridView_resources->CurrentCell->RowIndex;

					if(npcgen->ResourceSets[r]->ResourceGroups->Length>0 && dataGridView_resourceGroups->CurrentCell->RowIndex>-1)
					{
						array<PW::Data::NpcGen::ResourceGroup^>^ temp = gcnew array<PW::Data::NpcGen::ResourceGroup^>(npcgen->ResourceSets[r]->ResourceGroups->Length-1);
						Array::Copy(npcgen->ResourceSets[r]->ResourceGroups, 0, temp, 0, dataGridView_resourceGroups->CurrentCell->RowIndex);
						Array::Copy(npcgen->ResourceSets[r]->ResourceGroups, dataGridView_resourceGroups->CurrentCell->RowIndex+1, temp, dataGridView_resourceGroups->CurrentCell->RowIndex, temp->Length - dataGridView_resourceGroups->CurrentCell->RowIndex);
						npcgen->ResourceSets[r]->ResourceGroups = temp;

						dataGridView_resourceGroups->Rows->RemoveAt(dataGridView_resourceGroups->CurrentCell->RowIndex);
						if(npcgen->ResourceSets[r]->ResourceGroups->Length>0)
						{
							dataGridView_resources->Rows[r]->HeaderCell->Value = npcgen->ResourceSets[r]->ResourceGroups[0]->ID.ToString();
						}
						else
						{
							dataGridView_resources->Rows[r]->HeaderCell->Value = "";
						}
						dataGridView_resources->Rows[r]->Cells[0]->Value = (dataGridView_resourceGroups->Rows->Count).ToString();
					}
				}
			}

			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_Dynamics)
			{
				if(npcgen->Dynamics->Length>0 && dataGridView_Dynamics->CurrentCell->RowIndex>-1)
				{
					array<PW::Data::NpcGen::Dynamic^>^ temp = gcnew array<PW::Data::NpcGen::Dynamic^>(npcgen->Dynamics->Length-1);
					Array::Copy(npcgen->Dynamics, 0, temp, 0, dataGridView_Dynamics->CurrentCell->RowIndex);
					Array::Copy(npcgen->Dynamics, dataGridView_Dynamics->CurrentCell->RowIndex+1, temp, dataGridView_Dynamics->CurrentCell->RowIndex, temp->Length - dataGridView_Dynamics->CurrentCell->RowIndex);
					npcgen->Dynamics = temp;

					dataGridView_Dynamics->Rows->RemoveAt(dataGridView_Dynamics->CurrentCell->RowIndex);
				}
			}

			if(contextMenuStrip_dataGrid->SourceControl == dataGridView_Triggers)
			{
				if(npcgen->Triggers->Length>0 && dataGridView_Triggers->CurrentCell->RowIndex>-1)
				{
					array<PW::Data::NpcGen::Trigger^>^ temp = gcnew array<PW::Data::NpcGen::Trigger^>(npcgen->Triggers->Length-1);
					Array::Copy(npcgen->Triggers, 0, temp, 0, dataGridView_Triggers->CurrentCell->RowIndex);
					Array::Copy(npcgen->Triggers, dataGridView_Triggers->CurrentCell->RowIndex+1, temp, dataGridView_Triggers->CurrentCell->RowIndex, temp->Length - dataGridView_Triggers->CurrentCell->RowIndex);
					npcgen->Triggers = temp;

					dataGridView_Triggers->Rows->RemoveAt(dataGridView_Triggers->CurrentCell->RowIndex);
				}
			}
		}
	}

	private: System::Void change_creatures(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(npcgen && dataGridView_creatures->CurrentCell)
		{
			try
			{
				int r = dataGridView_creatures->CurrentCell->RowIndex;
				switch (dataGridView_creatures->CurrentCell->ColumnIndex)
				{
					case 1:		npcgen->CreatureSets[r]->SpawnMode = Column1->Items->IndexOf(dataGridView_creatures->CurrentCell->Value);
								break;
					case 2:		npcgen->CreatureSets[r]->SpawnX = Convert::ToSingle(dataGridView_creatures->CurrentCell->Value);
								break;
					case 3:		npcgen->CreatureSets[r]->SpawnAltitude = Convert::ToSingle(dataGridView_creatures->CurrentCell->Value);
								break;
					case 4:		npcgen->CreatureSets[r]->SpawnZ = Convert::ToSingle(dataGridView_creatures->CurrentCell->Value);
								break;
					case 5:		npcgen->CreatureSets[r]->DirectionX = Convert::ToSingle(dataGridView_creatures->CurrentCell->Value);
								break;
					case 6:		npcgen->CreatureSets[r]->DirectionAltitude = Convert::ToSingle(dataGridView_creatures->CurrentCell->Value);
								break;
					case 7:		npcgen->CreatureSets[r]->DirectionZ = Convert::ToSingle(dataGridView_creatures->CurrentCell->Value);
								break;
					case 8:		npcgen->CreatureSets[r]->SpreadX = Convert::ToSingle(dataGridView_creatures->CurrentCell->Value);
								break;
					case 9:		npcgen->CreatureSets[r]->SpreadAltitude = Convert::ToSingle(dataGridView_creatures->CurrentCell->Value);
								break;
					case 10:	npcgen->CreatureSets[r]->SpreadZ = Convert::ToSingle(dataGridView_creatures->CurrentCell->Value);
								break;
					case 11:	npcgen->CreatureSets[r]->Type = Column12->Items->IndexOf(dataGridView_creatures->CurrentCell->Value);
								break;
					case 12:	npcgen->CreatureSets[r]->unknown_8 = Convert::ToInt32(dataGridView_creatures->CurrentCell->Value);
								break;
					case 13:	npcgen->CreatureSets[r]->unknown_9 = Convert::ToBoolean(dataGridView_creatures->CurrentCell->Value);
								break;
					case 14:	npcgen->CreatureSets[r]->unknown_10 = Convert::ToBoolean(dataGridView_creatures->CurrentCell->Value);
								break;
					case 15:	npcgen->CreatureSets[r]->InstantRespawn = Convert::ToBoolean(dataGridView_creatures->CurrentCell->Value);
								break;
					case 16:	npcgen->CreatureSets[r]->unknown_12 = Convert::ToInt32(dataGridView_creatures->CurrentCell->Value);
								break;
					case 17:	npcgen->CreatureSets[r]->TriggerID = Convert::ToInt32(dataGridView_creatures->CurrentCell->Value);
								break;
					case 18:	npcgen->CreatureSets[r]->unknown_14 = Convert::ToInt32(dataGridView_creatures->CurrentCell->Value);
								break;
					case 19:	npcgen->CreatureSets[r]->unknown_15 = Convert::ToInt32(dataGridView_creatures->CurrentCell->Value);
								break;
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_creatureGroups(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(npcgen && dataGridView_creatures->CurrentCell && dataGridView_creatureGroups->CurrentCell)
		{
			try
			{
				int r = dataGridView_creatures->CurrentCell->RowIndex;
				int n = dataGridView_creatureGroups->CurrentCell->RowIndex;

				switch (dataGridView_creatureGroups->CurrentCell->ColumnIndex)
				{
					case 0:		npcgen->CreatureSets[r]->CreatureGroups[n]->ID = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								if(n == 0)
								{
									dataGridView_creatures->Rows[r]->HeaderCell->Value = "[" + npcgen->CreatureSets[r]->CreatureGroups[0]->ID.ToString() + "] " + npcName(npcgen->CreatureSets[r]->CreatureGroups[0]->ID);
								}
								dataGridView_creatureGroups->Rows[n]->HeaderCell->Value = npcName(npcgen->CreatureSets[r]->CreatureGroups[n]->ID);
								break;
					case 1:		npcgen->CreatureSets[r]->CreatureGroups[n]->Amount = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 2:		npcgen->CreatureSets[r]->CreatureGroups[n]->Respawn = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 3:		npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_2 = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 4:		npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_3 = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 5:		npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_4 = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 6:		npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_5 = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 7:		npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_6 = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 8:		npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_7 = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 9:		npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_8 = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 10:	npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_9 = Convert::ToBoolean(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 11:	npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_10 = Convert::ToBoolean(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 12:	npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_11 = Convert::ToBoolean(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 13:	npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_12 = Convert::ToBoolean(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 14:	npcgen->CreatureSets[r]->CreatureGroups[n]->PathID = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 15:	npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_14 = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 16:	npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_15 = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
					case 17:	npcgen->CreatureSets[r]->CreatureGroups[n]->unknown_16 = Convert::ToInt32(dataGridView_creatureGroups->CurrentCell->Value);
								break;
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_resources(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(npcgen && dataGridView_resources->CurrentCell)
		{
			try
			{
				int r = dataGridView_resources->CurrentCell->RowIndex;
				switch (dataGridView_resources->CurrentCell->ColumnIndex)
				{
					case 1:		npcgen->ResourceSets[r]->SpawnX = Convert::ToSingle(dataGridView_resources->CurrentCell->Value);
								break;
					case 2:		npcgen->ResourceSets[r]->SpawnAltitude = Convert::ToSingle(dataGridView_resources->CurrentCell->Value);
								break;
					case 3:		npcgen->ResourceSets[r]->SpawnZ = Convert::ToSingle(dataGridView_resources->CurrentCell->Value);
								break;
					case 4:		npcgen->ResourceSets[r]->SpreadX = Convert::ToSingle(dataGridView_resources->CurrentCell->Value);
								break;
					case 5:		npcgen->ResourceSets[r]->SpreadZ = Convert::ToSingle(dataGridView_resources->CurrentCell->Value);
								break;
					case 6:		npcgen->ResourceSets[r]->unknown_1 = Convert::ToBoolean(dataGridView_resources->CurrentCell->Value);
								break;
					case 7:		npcgen->ResourceSets[r]->unknown_2 = Convert::ToBoolean(dataGridView_resources->CurrentCell->Value);
								break;
					case 8:		npcgen->ResourceSets[r]->unknown_3 = Convert::ToBoolean(dataGridView_resources->CurrentCell->Value);
								break;
					case 9:		npcgen->ResourceSets[r]->unknown_4 = Convert::ToInt32(dataGridView_resources->CurrentCell->Value);
								break;
					case 10:	npcgen->ResourceSets[r]->unknown_5a = Convert::ToByte(dataGridView_resources->CurrentCell->Value);
								break;
					case 11:	npcgen->ResourceSets[r]->unknown_5b = Convert::ToByte(dataGridView_resources->CurrentCell->Value);
								break;
					case 12:	npcgen->ResourceSets[r]->unknown_5c = Convert::ToByte(dataGridView_resources->CurrentCell->Value);
								break;
					case 13:	npcgen->ResourceSets[r]->TriggerID = Convert::ToInt32(dataGridView_resources->CurrentCell->Value);
								break;
					case 14:	npcgen->ResourceSets[r]->unknown_6 = Convert::ToByte(dataGridView_resources->CurrentCell->Value);
								break;
					case 15:	npcgen->ResourceSets[r]->unknown_7 = Convert::ToBoolean(dataGridView_resources->CurrentCell->Value);
								break;
					case 16:	npcgen->ResourceSets[r]->unknown_8 = Convert::ToBoolean(dataGridView_resources->CurrentCell->Value);
								break;
					case 17:	npcgen->ResourceSets[r]->unknown_9 = Convert::ToBoolean(dataGridView_resources->CurrentCell->Value);
								break;
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}

	private: System::Void change_resourceGroups(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(npcgen && dataGridView_resources->CurrentCell && dataGridView_resourceGroups->CurrentCell)
		{
			try
			{
				int r = dataGridView_resources->CurrentCell->RowIndex;
				int n = dataGridView_resourceGroups->CurrentCell->RowIndex;
				switch (dataGridView_resourceGroups->CurrentCell->ColumnIndex)
				{
					case 0:		npcgen->ResourceSets[r]->ResourceGroups[n]->unknown_1 = Convert::ToInt32(dataGridView_resourceGroups->CurrentCell->Value);
								break;
					case 1:		npcgen->ResourceSets[r]->ResourceGroups[n]->ID = Convert::ToInt32(dataGridView_resourceGroups->CurrentCell->Value);
								if(n == 0)
								{
									dataGridView_resources->Rows[r]->HeaderCell->Value = npcgen->ResourceSets[r]->ResourceGroups[0]->ID.ToString();
								}	
								break;
					case 2:		npcgen->ResourceSets[r]->ResourceGroups[n]->Respawn = Convert::ToInt32(dataGridView_resourceGroups->CurrentCell->Value);	
								break;
					case 3:		npcgen->ResourceSets[r]->ResourceGroups[n]->Amount = Convert::ToInt32(dataGridView_resourceGroups->CurrentCell->Value);
								break;
					case 4:		npcgen->ResourceSets[r]->ResourceGroups[n]->unknown_2 = Convert::ToInt32(dataGridView_resourceGroups->CurrentCell->Value);
								break;
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_Dynamics(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(npcgen && dataGridView_Dynamics->CurrentCell)
		{
			try
			{
				int r = dataGridView_Dynamics->CurrentCell->RowIndex;
				switch (dataGridView_Dynamics->CurrentCell->ColumnIndex)
				{
					case 0:		npcgen->Dynamics[r]->ID = Convert::ToInt32(dataGridView_Dynamics->CurrentCell->Value);
								break;
					case 1:		npcgen->Dynamics[r]->SpawnX = Convert::ToSingle(dataGridView_Dynamics->CurrentCell->Value);
								break;
					case 2:		npcgen->Dynamics[r]->SpawnAltitude = Convert::ToSingle(dataGridView_Dynamics->CurrentCell->Value);
								break;
					case 3:		npcgen->Dynamics[r]->SpawnZ = Convert::ToSingle(dataGridView_Dynamics->CurrentCell->Value);
								break;
					case 4:		npcgen->Dynamics[r]->unknown_5 = Convert::ToByte(dataGridView_Dynamics->CurrentCell->Value);
								break;
					case 5:		npcgen->Dynamics[r]->unknown_6 = Convert::ToByte(dataGridView_Dynamics->CurrentCell->Value);
								break;
					case 6:		npcgen->Dynamics[r]->unknown_7 = Convert::ToByte(dataGridView_Dynamics->CurrentCell->Value);
								break;
					case 7:		npcgen->Dynamics[r]->TriggerID = Convert::ToInt32(dataGridView_Dynamics->CurrentCell->Value);
								break;
					case 8:		npcgen->Dynamics[r]->unknown_8 = Convert::ToByte(dataGridView_Dynamics->CurrentCell->Value);
								break;
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void change_Triggers(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if(npcgen && dataGridView_Triggers->CurrentCell)
		{
			try
			{
				int r = dataGridView_Triggers->CurrentCell->RowIndex;
				switch (dataGridView_Triggers->CurrentCell->ColumnIndex)
				{
					case 0:		npcgen->Triggers[r]->TriggerID = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 1:		npcgen->Triggers[r]->CreatureBuilderID = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 2:		npcgen->Triggers[r]->Name = getBytesGBK(dataGridView_Triggers->CurrentCell->Value->ToString());
								break;
					case 3:		npcgen->Triggers[r]->unknown_3 = Convert::ToBoolean(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 4:		npcgen->Triggers[r]->AutostartDelayTime = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 5:		npcgen->Triggers[r]->AutostopDelayTime = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 6:		npcgen->Triggers[r]->AutostartDisable = Convert::ToBoolean(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 7:		npcgen->Triggers[r]->AutostopDisable = Convert::ToBoolean(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 8:		npcgen->Triggers[r]->StartYear = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 9:		npcgen->Triggers[r]->StartMonth = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 10:	npcgen->Triggers[r]->StartWeekDay = Column42->Items->IndexOf(dataGridView_Triggers->CurrentCell->Value)-1;
								break;
					case 11:	npcgen->Triggers[r]->StartDay = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 12:	npcgen->Triggers[r]->StartHour = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 13:	npcgen->Triggers[r]->StartMinute = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 14:	npcgen->Triggers[r]->EndYear = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 15:	npcgen->Triggers[r]->EndMonth = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 16:	npcgen->Triggers[r]->EndWeekDay = Column43->Items->IndexOf(dataGridView_Triggers->CurrentCell->Value)-1;
								break;
					case 17:	npcgen->Triggers[r]->EndDay = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 18:	npcgen->Triggers[r]->EndHour = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 19:	npcgen->Triggers[r]->EndMinute = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
					case 20:	npcgen->Triggers[r]->Duration = Convert::ToInt32(dataGridView_Triggers->CurrentCell->Value);
								break;
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void click_search(System::Object^  sender, System::EventArgs^  e)
	{
		if(npcgen)
		{
			try
			{
				int pattern = Convert::ToInt32(textBox_search->Text);

				if(tabControl1->SelectedIndex == 0)
				{
					int i = dataGridView_creatures->CurrentRow->Index;
					if(i<0)
					{
						i = 0;
					}
					for(i; i<npcgen->CreatureSets->Length; i++)
					{
						int n = 0;
						// first run -> drop selected creaturegroup item
						if(i == dataGridView_creatures->CurrentRow->Index)
						{
							n = dataGridView_creatureGroups->CurrentRow->Index+1;
						}
						if(n>=dataGridView_creatureGroups->Rows->Count)
						{
							i++;
							n=0;
						}
						if(i<npcgen->CreatureSets->Length)
						{
							for(n; n<npcgen->CreatureSets[i]->CreatureGroups->Length; n++)
							{
								if(npcgen->CreatureSets[i]->CreatureGroups[n]->ID == pattern)
								{
									dataGridView_creatures->CurrentCell = dataGridView_creatures->Rows[i]->Cells[0];
									dataGridView_creatureGroups->CurrentCell = dataGridView_creatureGroups->Rows[n]->Cells[0];
									return;
								}
							}
						}
					}
					MessageBox::Show("Search reached End of File");
				}

				if(tabControl1->SelectedIndex == 1)
				{
					int i = dataGridView_resources->CurrentRow->Index;
					if(i<0)
					{
						i = 0;
					}
					for(i; i<npcgen->ResourceSets->Length; i++)
					{
						int n = 0;
						// first run -> drop selected creaturegroup item
						if(i == dataGridView_resources->CurrentRow->Index)
						{
							n = dataGridView_resourceGroups->CurrentRow->Index+1;
						}
						if(n>=dataGridView_resourceGroups->Rows->Count)
						{
							i++;
							n=0;
						}
						if(i<npcgen->ResourceSets->Length)
						{
							for(n; n<npcgen->ResourceSets[i]->ResourceGroups->Length; n++)
							{
								if(npcgen->ResourceSets[i]->ResourceGroups[n]->ID == pattern)
								{
									dataGridView_resources->CurrentCell = dataGridView_resources->Rows[i]->Cells[0];
									dataGridView_resourceGroups->CurrentCell = dataGridView_resourceGroups->Rows[n]->Cells[0];
									return;
								}
							}
						}
					}
					MessageBox::Show("Search reached End of File");
				}

				if(tabControl1->SelectedIndex == 2)
				{
					int i = dataGridView_Dynamics->CurrentRow->Index+1;

					for(i; i<npcgen->Dynamics->Length; i++)
					{
						if(npcgen->Dynamics[i]->ID == pattern)
						{
							dataGridView_Dynamics->CurrentCell = dataGridView_Dynamics->Rows[i]->Cells[0];
							return;
						}
					}
					MessageBox::Show("Search reached End of File");
				}

				if(tabControl1->SelectedIndex == 3)
				{
					int i = dataGridView_Triggers->CurrentRow->Index+1;

					for(i; i<npcgen->Triggers->Length; i++)
					{
						if(npcgen->Triggers[i]->TriggerID == pattern)
						{
							dataGridView_Triggers->CurrentCell = dataGridView_Triggers->Rows[i]->Cells[0];
							return;
						}
					}
					MessageBox::Show("Search reached End of File");
				}
			}
			catch(...)
			{
				MessageBox::Show("FORMAT ERROR\nInput value must be in the correct format!");
			}
		}
	}
	private: System::Void click_getClientValues(System::Object^  sender, System::EventArgs^  e)
	{
		if(comboBox_AssistantClient->SelectedIndex > -1)
		{
			PW::Client::ClientValues^ values = ecInterface->GetProfileValues(ecInterface->OffsetProfiles[comboBox_AssistantClient->SelectedIndex]);

			if(values)
			{
				if(tabControl1->SelectedTab == tabPage_creatures && dataGridView_creatures->CurrentCell)
				{
					int r = dataGridView_creatures->CurrentCell->RowIndex;
/*
					if(dataGridView_creatureGroups->CurrentCell)
					{
						int n = dataGridView_creatureGroups->CurrentCell->RowIndex;
						dataGridView_creatureGroups->Rows[n]->Cells[0]->Value = textBox_AssistantNPCid->Text;
						npcgen->CreatureSets[r]->CreatureGroups[n]->ID = Convert::ToInt32(textBox_AssistantNPCid->Text);
						if(n == 0)
						{
							dataGridView_creatures->Rows[r]->HeaderCell->Value = "[" + textBox_AssistantNPCid->Text + "] " + npcName(npcgen->CreatureSets[r]->CreatureGroups[0]->ID);
						}
					}
*/
					dataGridView_creatures->Rows[r]->Cells[2]->Value = values->TargetPositionX.ToString("F3");
					npcgen->CreatureSets[r]->SpawnX = values->TargetPositionX;
					dataGridView_creatures->Rows[r]->Cells[3]->Value = values->TargetPositionY.ToString("F3");
					npcgen->CreatureSets[r]->SpawnAltitude = values->TargetPositionY;
					dataGridView_creatures->Rows[r]->Cells[4]->Value = values->TargetPositionZ.ToString("F3");
					npcgen->CreatureSets[r]->SpawnZ = values->TargetPositionZ;
					dataGridView_creatures->Rows[r]->Cells[5]->Value = values->TargetDirectionX.ToString("F3");
					npcgen->CreatureSets[r]->DirectionX = values->TargetDirectionX;
					dataGridView_creatures->Rows[r]->Cells[6]->Value = values->TargetDirectionY.ToString("F3");
					npcgen->CreatureSets[r]->DirectionAltitude = values->TargetDirectionY;
					dataGridView_creatures->Rows[r]->Cells[7]->Value = values->TargetDirectionZ.ToString("F3");
					npcgen->CreatureSets[r]->DirectionZ = values->TargetDirectionZ;
				}

				if(tabControl1->SelectedTab == tabPage_resources && dataGridView_resources->CurrentCell)
				{
					int r = dataGridView_resources->CurrentCell->RowIndex;

					dataGridView_resources->Rows[r]->Cells[1]->Value = values->TargetPositionX.ToString("F3");
					npcgen->ResourceSets[r]->SpawnX = values->TargetPositionX;
					dataGridView_resources->Rows[r]->Cells[2]->Value = values->TargetPositionY.ToString("F3");
					npcgen->ResourceSets[r]->SpawnAltitude = values->TargetPositionY;
					dataGridView_resources->Rows[r]->Cells[3]->Value = values->TargetPositionZ.ToString("F3");
					npcgen->ResourceSets[r]->SpawnZ = values->TargetPositionZ;
				}

				if(tabControl1->SelectedTab == tabPage_Dynamics)
				{
					int r = dataGridView_Dynamics->CurrentCell->RowIndex;

					dataGridView_Dynamics->Rows[r]->Cells[1]->Value = values->TargetPositionX.ToString("F3");
					npcgen->Dynamics[r]->SpawnX = values->TargetPositionX;
					dataGridView_Dynamics->Rows[r]->Cells[2]->Value = values->TargetPositionY.ToString("F3");
					npcgen->Dynamics[r]->SpawnAltitude = values->TargetPositionY;
					dataGridView_Dynamics->Rows[r]->Cells[3]->Value = values->TargetPositionZ.ToString("F3");
					npcgen->Dynamics[r]->SpawnZ = values->TargetPositionZ;
				}
			}
		}
	}
};