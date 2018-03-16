
// 进制转换Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "进制转换.h"
#include "进制转换Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C进制转换Dlg 对话框



C进制转换Dlg::C进制转换Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, m_num1(0)
	, m_result(0)
	, m_num2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C进制转换Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUM1, m_num1);
	DDX_Text(pDX, IDC_RESULT, m_result);
	DDX_Radio(pDX, IDC_TWO, m_num2);
}

BEGIN_MESSAGE_MAP(C进制转换Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_NUM1, &C进制转换Dlg::OnEnChangeNum1)
	ON_BN_CLICKED(IDC_TWO, &C进制转换Dlg::OnBnClickedTwo)
	ON_BN_CLICKED(IDC_EIGHT, &C进制转换Dlg::OnBnClickedEight)
	ON_BN_CLICKED(IDC_TEN, &C进制转换Dlg::OnBnClickedTen)
	ON_BN_CLICKED(IDC_SIX, &C进制转换Dlg::OnBnClickedSix)
	ON_BN_CLICKED(IDC_RESET, &C进制转换Dlg::OnBnClickedReset)
END_MESSAGE_MAP()


// C进制转换Dlg 消息处理程序

BOOL C进制转换Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C进制转换Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C进制转换Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C进制转换Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C进制转换Dlg::OnEnChangeNum1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	
}


void C进制转换Dlg::OnBnClickedTwo()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_num2 = 2;
	int a[20];
	int i = 0;
	//m_result = 0;
	while (m_num1)
	{
		a[i++] = m_num1%m_num2;
		m_num1 = m_num1 / m_num2;
	}
	int k = i - 1;
	for (i = 0; i <= k; i++)
		m_result += a[i] * pow(10.0, i);
	UpdateData(FALSE);
}


void C进制转换Dlg::OnBnClickedEight()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_num2 = 8;
	int a[20];
	int i = 0;
	//m_result = 0;
	while (m_num1)
	{
		a[i++] = m_num1%m_num2;
		m_num1 = m_num1 / m_num2;
	}
	int k = i - 1;
	for (i = 0; i <= k; i++)
		m_result += a[i] * pow(10.0, i);
	UpdateData(FALSE);
}


void C进制转换Dlg::OnBnClickedTen()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_num2 = 10;
	int a[20];
	int i = 0;
	//m_result = 0;
	while (m_num1)
	{
		a[i++] = m_num1%m_num2;
		m_num1 = m_num1 / m_num2;
	}
	int k = i - 1;
	for (i = 0; i <= k; i++)
		m_result += a[i] * pow(10.0, i);
	UpdateData(FALSE);
}


void C进制转换Dlg::OnBnClickedSix()
{
	// TODO: 在此添加控件通知处理程序代码
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_num2 = 16;
	int a[20];
	int i = 0;
	//m_result = 0;
	while (m_num1)
	{
		a[i++] = m_num1%m_num2;
		m_num1 = m_num1 / m_num2;
	}
	int k = i - 1;
	for (i = 0; i <= k; i++)
		m_result += a[i] * pow(10.0, i);
	UpdateData(FALSE);
}


void C进制转换Dlg::OnBnClickedReset()
{
	// TODO: 在此添加控件通知处理程序代码
	m_result = m_num1 = m_num2 = 0;
	UpdateData(FALSE);
}
