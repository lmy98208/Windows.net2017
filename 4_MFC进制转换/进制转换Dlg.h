
// 进制转换Dlg.h : 头文件
//

#pragma once


// C进制转换Dlg 对话框
class C进制转换Dlg : public CDialogEx
{
// 构造
public:
	C进制转换Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
