// SignupDlg.cpp: 구현 파일
//

#include "pch.h"
#include "Book_Management.h"
#include "SignupDlg.h"
#include "afxdialogex.h"


// SignupDlg 대화 상자

IMPLEMENT_DYNAMIC(SignupDlg, CDialogEx)

SignupDlg::SignupDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIGNUP, pParent)
	, m_strTel(_T(""))
	, m_strPW2(_T(""))
	, m_strPW(_T(""))
	, m_strName(_T(""))
	, m_strID(_T(""))
{

}

SignupDlg::~SignupDlg()
{
}

void SignupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEL, m_strTel);
	DDX_Text(pDX, IDC_EDIT_PW2, m_strPW2);
	DDX_Text(pDX, IDC_EDIT_PW, m_strPW);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_ID, m_strID);
}


BEGIN_MESSAGE_MAP(SignupDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SIGNUP, &SignupDlg::OnBnClickedButtonSignup)
END_MESSAGE_MAP()


// SignupDlg 메시지 처리기


void SignupDlg::OnBnClickedButtonSignup()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);;

	// 빈칸이 있을 경우
	if ((CStringA)m_strID == "" || (CStringA)m_strPW == "" || (CStringA)m_strPW2 == "" || (CStringA)m_strName == "" || (CStringA)m_strTel == "")
		MessageBox(TEXT("모든 항목을 입력해주세요."), TEXT("회원가입 실패"), MB_OK);
	// 비밀번호 확인
	else if ((CStringA)m_strPW != (CStringA)m_strPW2)
		MessageBox(TEXT("비밀번호를 확인해주세요."), TEXT("회원가입 실패"), MB_OK);
	else
	{
		mysql_init(&Connect);
		mysql_real_connect(&Connect, MY_IP, DB_USER, DB_PASS, DB_NAME, 3306, (char*)NULL, 0);
		mysql_query(&Connect, "set names euckr");
		CString query;
		query.Format(_T("select * from user where id = '%s' and pw = '%s'"), m_strPW, m_strID);
		mysql_query(&Connect, (CStringA)query);
		Sql_Result = mysql_store_result(&Connect);
		if ((Sql_Row = mysql_fetch_row(Sql_Result)) != NULL)
		{
			MessageBox(TEXT("이미 존재하는 아이디입니다."), TEXT("회원가입 실패"), MB_OK);
		}
		else
		{
			query.Format(_T("insert into user (id, pw, name, tel, book) values ('%s', '%s', '%s', '%s', 0)"), m_strID, m_strPW, m_strName, m_strTel);
			mysql_query(&Connect, (CStringA)query);
			Sql_Result = mysql_store_result(&Connect);
			MessageBox(query, TEXT("회원가입 성공"), MB_OK);
			OnOK();
		}
		mysql_close(&Connect);
	}
}