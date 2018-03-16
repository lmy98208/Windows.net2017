
// ����ת��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ת��.h"
#include "����ת��Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C����ת��Dlg �Ի���



C����ת��Dlg::C����ת��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY_DIALOG, pParent)
	, m_num1(0)
	, m_result(0)
	, m_num2(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C����ת��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NUM1, m_num1);
	DDX_Text(pDX, IDC_RESULT, m_result);
	DDX_Radio(pDX, IDC_TWO, m_num2);
}

BEGIN_MESSAGE_MAP(C����ת��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_NUM1, &C����ת��Dlg::OnEnChangeNum1)
	ON_BN_CLICKED(IDC_TWO, &C����ת��Dlg::OnBnClickedTwo)
	ON_BN_CLICKED(IDC_EIGHT, &C����ת��Dlg::OnBnClickedEight)
	ON_BN_CLICKED(IDC_TEN, &C����ת��Dlg::OnBnClickedTen)
	ON_BN_CLICKED(IDC_SIX, &C����ת��Dlg::OnBnClickedSix)
	ON_BN_CLICKED(IDC_RESET, &C����ת��Dlg::OnBnClickedReset)
END_MESSAGE_MAP()


// C����ת��Dlg ��Ϣ�������

BOOL C����ת��Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C����ת��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C����ת��Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C����ת��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C����ת��Dlg::OnEnChangeNum1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	
}


void C����ת��Dlg::OnBnClickedTwo()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void C����ת��Dlg::OnBnClickedEight()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void C����ת��Dlg::OnBnClickedTen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void C����ת��Dlg::OnBnClickedSix()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void C����ת��Dlg::OnBnClickedReset()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_result = m_num1 = m_num2 = 0;
	UpdateData(FALSE);
}
