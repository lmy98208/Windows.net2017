
// ����ת��Dlg.h : ͷ�ļ�
//

#pragma once


// C����ת��Dlg �Ի���
class C����ת��Dlg : public CDialogEx
{
// ����
public:
	C����ת��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_num1;
	int m_result;
	int m_num2;
	afx_msg void OnEnChangeNum1();
	afx_msg void OnBnClickedTwo();
	afx_msg void OnBnClickedEight();
	afx_msg void OnBnClickedTen();
	afx_msg void OnBnClickedSix();
	afx_msg void OnBnClickedReset();
};
