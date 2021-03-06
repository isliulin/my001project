// CapuleDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CapuleDemo.h"
#include "CapuleDemoDlg.h"
#include "TImgProcess.h"
#include "TBmpInfo.h "
#include "TBmpBoard.h "
#include "iCVFoundation.h"

#pragma comment(lib, "cvfoundation.lib")




#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCapuleDemoDlg 对话框




CCapuleDemoDlg::CCapuleDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCapuleDemoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCapuleDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CVDISPLAYCTRL1, m_display);
	DDX_Control(pDX, IDC_CVIMAGECTRL1, m_imageControl);
}

BEGIN_MESSAGE_MAP(CCapuleDemoDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CCapuleDemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCapuleDemoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCapuleDemoDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCapuleDemoDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCapuleDemoDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CCapuleDemoDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CCapuleDemoDlg 消息处理程序

BOOL CCapuleDemoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_display.SetLeftButtonMode(2);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCapuleDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCapuleDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
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
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR CCapuleDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCapuleDemoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CFileDialog dlg( TRUE,									//file open
		_T("mfd"),											//file ext
		_T("*.mfd"),										//file name
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,				// flags
		_T("Multi Frame file (*.mfd)|*.mfd|"));				// filter

	dlg.m_ofn.lpstrInitialDir = GetExeFileDir().c_str();

	if(IDOK == dlg.DoModal())
	{
		CString fileName = dlg.GetPathName();
		TMfdArchive mfdFile;
/*		for(int i = 0; i < THREADCOUNT; i++)
		{
			//m_firstThread[i].SetThreadFunc	(	CapsuleSorterDlg::FirstCamFunc, this);
			m_firstThread[i].Start(TThread::HIGHEST);
			//m_secondThread[i].SetThreadFunc(	CapsuleSorterDlg::SecondCamFunc, this);		
			m_secondThread[i].Start(TThread::HIGHEST);
		}
		*/
		if(mfdFile.Load(LPCTSTR(fileName)))
		{
			m_buff = mfdFile.GetImgBuffer();	
		}
	}
	//m_buff.GoNextFrame();
	IMG dispImg = GetIMGFromBuffer(m_buff);
	m_display.SetImage((long)dispImg);

/*	TImgDim	dim = m_simCam.ImageDimension();
	m_firstProcess.ReInit(dim);
	dim = m_secondSimCam.ImageDimension();
	m_secondProcess.ReInit(dim);
	*/
}

std::string&	CCapuleDemoDlg::GetExeFileDir	()
{
	static	std::string		exeFileDir;
	if (!exeFileDir.size())
	{
		char	filePath[MAX_PATH];
		GetModuleFileName(NULL, filePath, MAX_PATH);
		exeFileDir = filePath;
		size_t pathDot = exeFileDir.rfind("\\") + 1;
		exeFileDir = exeFileDir.substr(0, pathDot);
	}
	return exeFileDir;
}

IMG CCapuleDemoDlg::GetIMGFromBuffer(TImgBuffer & buffer)
{
	TImgDim dim = buffer.Dimension();
	IMG		imgOut;
	CreateImageFromPointer(buffer.FrameData(), dim.bytesPerRow * dim.height, dim.width, dim.height,
		dim.bytesPerPixel, 8,1, dim.bytesPerRow, dim.bytesPerPixel, 0, 0, 0, imgOut);
	return imgOut;

}
IMG CCapuleDemoDlg::GetIMGFromImage(TImage<PelGray8> & image)
{
	TImgDim dim = image.Dimension();
	IMG		imgOut;
	CreateImageFromPointer(image.Base(), dim.bytesPerRow * dim.height, dim.width, dim.height,
		dim.bytesPerPixel, 8,1, dim.bytesPerRow, dim.bytesPerPixel, 0, 0, 0, imgOut);
	return imgOut;

}
void CCapuleDemoDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	TImgDim				dim = m_buff.Dimension();
	TRect2D<int>		rt(0, 0, dim.width- 1, dim.height -1);
	TImage<PelGray8>	sourceImage(rt);
	//TImage<PelGray8>	enhanceImage;
	m_enhanceImage.ReInit(rt);
	sourceImage.SetImage(m_buff.FrameData(), m_buff.Dimension());
//	m_enhanceImage.SetImage(m_buff.FrameData(), m_buff.Dimension());
	TImgProcess::SobelFilter(sourceImage, m_enhanceImage);
	IMG dispImg = GetIMGFromImage(m_enhanceImage);
	m_display.SetImage((long)dispImg);
}

void CCapuleDemoDlg::OnBnClickedButton3()
{
	TImgDim				dim = m_buff.Dimension();
	TRect2D<int>		rt(0, 0, dim.width- 1, dim.height -1);
	TImage<PelGray8>	sourceImage(rt);

	m_binaryImage.ReInit(rt);

	sourceImage.SetImage(m_buff.FrameData(), m_buff.Dimension());

	TImgProcess::BinaryGray(sourceImage, m_binaryImage, 10, 255 );
	IMG dispImg = GetIMGFromImage(m_binaryImage);
	m_display.SetImage((long)dispImg);

}

void CCapuleDemoDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_display.RemoveAllLabels();
	double x0, y0,x1,y1,x2,y2;
	m_display.GetSelectedArea(&x0, &y0, &x1, &y1, &x2, &y2);
	IMG		sourceIMG = GetIMGFromImage(m_sourceImage);
	IMG		subImage = NULL;
	const	int subWidth = ((int)(x2 -x0))/4 *4;
	TArea area;
	area.X0 = x0;
	area.Y0 = y0;
	area.X1 = x1;
	area.Y1 = y1;
	area.X2 = x0 + subWidth-1;
	area.Y2 = y2;
	TCoordinateMap cm;
	InitCoordinateMap(cm);
	SetImageCoordinates (sourceIMG, cm); 	
	CreateSubImage(sourceIMG, area, subImage);

	InitCoordinateMap(cm);
	SetImageCoordinates (sourceIMG, cm); 	
	TImage<PelGray8>	dstImage= GetTImageFromIMG(subImage);
	

	TBmpInfo info;
	info.Width	(ImageWidth(subImage));
	info.Height	(ImageHeight(subImage));
	info.AccordMem();

	TBmpBoard bmpBoard;
	bmpBoard.SetBmpInfo(info);
	PixelMem *pPixel = bmpBoard.GetPixelBase();
	memcpy(pPixel, dstImage.Base(), dstImage.Width() * dstImage.Height());
	HDC memHDC = bmpBoard.GetMemDC();
	ArcTemple uptemp	= ArcCreator::CreateArc(69, ArcTemple::eUpArc);
	ArcTemple downTemp	= ArcCreator::CreateArc(70, ArcTemple::eDownArc);
	TPoint2D<int>	upCentre;
	TPoint2D<int>	downCentre;

	const int imgWidth = ImageWidth(subImage);
	const int imgHeight = ImageHeight(subImage);
	TRect2D<int>	subArea(0, 0, imgWidth-1, imgHeight-1);
	
	//	long	upSpeciSide		= rectSet[i].top + (rectSet[i].bottom - rectSet[i].top)/3;
	//	long	downSpeciSide	= rectSet[i].top + (rectSet[i].bottom - rectSet[i].top)*2/3;
	//	TRect2D<int>	selectUpArea(rectSet[i].left, rectSet[i].top, rectSet[i].right-1, upSpeciSide);
	//	TRect2D<int>	selectDownArea(rectSet[i].left, downSpeciSide, rectSet[i].right, rectSet[i].bottom);
	m_display.SetImage((long)subImage);
	//IMG		dispImg = GetIMGFromImage(dstImage);
	//m_display.SetImage((long)dispImg);
//	TImage<PelGray8> srcImage = GetTImageFromIMG(subImage);
	GetTopPos(dstImage, subArea, upCentre, m_tempSet);
	CoorArray	arry = downTemp.GetCoorArray();
	for (int i = 0; i < m_tempSet.size(); i++)
	{
		m_display.AddLabel("up", FALSE, 255, 0,  upCentre.x() +m_tempSet.at(i).x,  upCentre.y() +m_tempSet.at(i).y);
	}
	

		//if (!selectUpArea.Within(upCentre.x(), upCentre.y()))
		//{
		//	upCentre = selectUpArea.Center();
		//}
		//GetTopPos(srcImage, selectDownArea, downCentre, downTemp);
		//if (!selectDownArea.Within(downCentre.x(), downCentre.y()))
		//{
		//	downCentre = selectDownArea.Center();
		//}

		//FillDest(dstImage, upCentre, downCentre, memHDC, radius);
	

	//memcpy(dstImage.Base(), pPixel, dstImage.Width()* dstImage.Height());
}


void CCapuleDemoDlg::GetTopPos(	TImage<unsigned char>		&image,
							 TRect2D<int>				&rect, 
							 TPoint2D<int>				&centre,
							 ArcTemple					&temp)
{
	ArcMatchor matchor;
	matchor.SetImage(image);	
	matchor.GetMaxMatchPos(temp, rect, centre);
}

TImage<PelGray8>	CCapuleDemoDlg::GetTImageFromIMG(IMG img)
{
	const int imgWidth = ImageWidth(img);
	const int imgHeight = ImageHeight(img);
	TRect2D<int>	rt(0, 0, imgWidth-1, imgHeight -1);
	TImage<PelGray8>	subImage(rt);
	PVPAT	vpa = NULL;
	unsigned char *pImage = NULL;
	GetImageVPA(img, 0, (void**)&pImage, &vpa);
	for (int i = 0; i < imgHeight; i++)
	{
		for (int j = 0; j < imgWidth; j++)
		{
			subImage.SetPixel(j, i, *(vpa[j].XEntry + pImage + vpa[i].YEntry));
		}
	}
	//memcpy(subImage.Base(), pImage,imgWidth * imgHeight);
	return subImage;
}
void CCapuleDemoDlg::OnBnClickedButton5()
{
	TImgDim				dim = m_buff.Dimension();
	TRect2D<int>		rt(0, 0, dim.width- 1, dim.height -1);
	m_sourceImage.ReInit(rt);
	IMG		sourceIMG = GetIMGFromImage(m_binaryImage);
	IMG		minBoxFilter = NULL;
	const	int boxWidth = 20;
	ErodeImage(sourceIMG, MM_Cross, boxWidth,boxWidth, boxWidth/2 -5, boxWidth/2-5, NULL, minBoxFilter);
	//FilterBoxMin(sourceIMG, 7,7, 3, 3, minBoxFilter);
	m_binaryImage= GetTImageFromIMG(minBoxFilter);

	TImgProcess::AndGrayImg(m_enhanceImage, m_binaryImage, m_sourceImage);

	IMG dispImg = GetIMGFromImage(m_sourceImage);
	m_display.SetImage((long)dispImg);
}

void CCapuleDemoDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码

	if (!m_imageControl.LoadImageByDialog())
	{
		return;
	}
	m_display.SetImage(m_imageControl.GetImage());
	const int imgWidth = ImageWidth((IMG)(m_imageControl.GetImage()));
	const int imgHeight = ImageHeight((IMG)(m_imageControl.GetImage()));
	TRect2D<int>	rt(0, 0, imgWidth - 1, imgHeight -1);
	TImage<PelGray8>	subImage(rt);
	PVPAT	vpa = NULL;
	unsigned char *pImage = NULL;
	GetImageVPA((IMG)m_imageControl.GetImage(), 0, (void**)&pImage, &vpa);
	
	memcpy(subImage.Base(), pImage,imgWidth * imgHeight);
	
	m_tempSet.clear();
	for (int i = 0; i < imgHeight; i++)
	{
		unsigned char *pLine = subImage.Base() + i * imgWidth;
		for (int j = 0; j < imgWidth; j++)
		{
			if (*(pLine + j) == 0)
			{
				POINT pt;
				pt.x = j;
				pt.y = i;
				m_tempSet.push_back(pt);
				//m_display.AddLabel("up", FALSE, 255, 0, j ,  i);
			}			
		}
	}
	//TImage<PelGray8>	srcImage = GetTImageFromIMG((IMG)m_imageControl.GetImage());
	//m_dispIM = GetIMGFromImage(tempImage);
	
	}

void CCapuleDemoDlg::GetTopPos(	TImage<unsigned char>		&image,
							   TRect2D<int>					&rect, 
							   TPoint2D<int>				&centre,
							   vector<POINT>					&temp)
{
	ArcMatchor matchor;
	matchor.SetImage(image);	
	matchor.GetMaxMatchPos(temp, rect, centre);
}
