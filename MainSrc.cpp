#include "Includes.hpp"

CONST CHAR ClassName[] = "mBot";
MSG Message;
WPARAM hNormalFont = (WPARAM)(HFONT)GetStockObject(DEFAULT_GUI_FONT);

//==================================================================================================

HWND MainFormHwnd; // G³ówne okno
HWND bSend; // Przycisk "Wyœlij"
HWND eMessage; // Pole edycyjne wiadomoœci
WNDPROC OldeMessageWndProc;
HWND eConversation; // Pole rozmowy

//==================================================================================================

LRESULT CALLBACK WndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK eMessageWndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX WndClass;

    WndClass.cbSize = sizeof (WNDCLASSEX); // Rozmiar struktury w bajtach
    WndClass.style = 0; // Style klasy
    WndClass.lpfnWndProc = WndProc; // WskaŸnik do procedury obs³uguj¹cej okno
    WndClass.cbClsExtra = 0; // Dodatkowe bajty pamiêci dla klasy
    WndClass.cbWndExtra = 0; // Dodatkowe bajty pamiêci dla klasy
    WndClass.hInstance = hInstance; // Identyfikator aplikacji, która ma byæ w³aœcicielem okna
    WndClass.hIcon = LoadIcon (hInstance, "APPICON"); // Ikona okna
    WndClass.hIconSm = LoadIcon (hInstance, "APPICON"); // Ma³a ikona okna
    WndClass.hCursor = LoadCursor (NULL, IDC_ARROW); // Kursor okna
    WndClass.hbrBackground = GetSysColorBrush(COLOR_3DFACE); // T³o okna
    WndClass.lpszMenuName = NULL; // Nazwa identyfikuj¹ca menu okna
    WndClass.lpszClassName = ClassName; // Nazwa klasy

    // Rejestrowanie klasy okna
    if (!RegisterClassEx(&WndClass))
    {
        MessageBox (NULL, "Nie mo¿na utworzyæ okna: b³¹d przy rejestrowaniu klasy!", "B³¹d", MB_ICONERROR | MB_OK);
        return 1;
    }

    //==================================================================================================
    // Tworzenie okna

    MainFormHwnd = CreateWindowEx (
        NULL,
        ClassName,
        "mBot 0.01",
        WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        500,
        400,
        NULL,
        NULL,
        hInstance,
        NULL);

    // Przycisk "Wyœlij"
    bSend = CreateButton(MainFormHwnd, hInstance, (char*)"Wyœlij", 380, 330, 100, 30);
    SendMessage(bSend, WM_SETFONT, hNormalFont, 0);

    // Pole edycyjne wiadomoœci
    HFONT eMessageFont = CreateFont (
        24,
        0,
        0,
        0,
        FW_DONTCARE,
        FALSE,
        FALSE,
        FALSE,
        DEFAULT_CHARSET,
        OUT_CHARACTER_PRECIS,
        CLIP_CHARACTER_PRECIS,
        DEFAULT_QUALITY,
        FF_DONTCARE,
        NULL);
    eMessage = CreateEditBox (MainFormHwnd, hInstance, 10, 330, 350, 30, false, false);
    SendMessage(eMessage, WM_SETFONT, (WPARAM) eMessageFont, 0);
    OldeMessageWndProc = (WNDPROC) SetWindowLong (eMessage, GWL_WNDPROC, (LONG)eMessageWndProc);

    // Pole rozmowy
    eConversation = CreateEditBox (MainFormHwnd, hInstance, 10, 10, 470, 300, true, true);
    SendMessage(eConversation, WM_SETFONT, hNormalFont, 0);

    //==================================================================================================

    InitTextsArray();

    if (MainFormHwnd == NULL)
    {
        MessageBox (NULL, "Nie mo¿na utworzyæ okna: b³¹d przy tworzeniu!", "B³¹d", MB_ICONERROR | MB_OK);
        return 1;
    }

    ShowWindow (MainFormHwnd, nCmdShow);
    UpdateWindow (MainFormHwnd);

    srand (time(0));

    // Pêtla komunikatów
    while (GetMessage (&Message, NULL, 0, 0))
    {
        TranslateMessage (&Message);
        DispatchMessage (&Message);
    }
    return Message.wParam;
}

void SendMessage ()
{
    if (GetWndText(eMessage) != "")
    {
        SetWindowText (eConversation, std::string (GetWndText(eConversation) + "Ja >> " + GetWndText(eMessage) + "\r\n").c_str());
        std::string Msg;
        Msg = AnalyzeMessage(GetWndText(eMessage));

        if (Msg != "")
        {
            unsigned int PreviousLine = 0;
            for (unsigned int i = 0; i < Msg.length(); i++)
                if (Msg[i] == '\n')
                {
                    SetWindowText (eConversation, std::string (GetWndText(eConversation) + "mBot >> " + Msg.substr(PreviousLine, i-PreviousLine) + "\r\n").c_str());
                    PreviousLine = i+1;
                }
                else if (i == Msg.length()-1)
                    SetWindowText (eConversation, std::string (GetWndText(eConversation) + "mBot >> " + Msg.substr(PreviousLine, i-PreviousLine+1) + "\r\n").c_str());
            SendMessage(eConversation, LOWORD(WM_VSCROLL), SB_BOTTOM, 0);
        }
        SetWindowText (eMessage, "");
    }
}

// Obs³uga zdarzeñ
LRESULT CALLBACK WndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_COMMAND:
            if ((HWND) lParam == bSend)
                SendMessage();
            break;

        case WM_CTLCOLORSTATIC:
        {
            HDC hEdit = (HDC)wParam;

            SetTextColor( hEdit, RGB(0, 0, 0) );
            SetBkColor ( hEdit, RGB(255, 255, 255) );

            // Do not return a brush created by CreateSolidBrush(...) because you'll get a memory leak
            return (INT_PTR)GetStockObject( WHITE_BRUSH );
        }

        case WM_CLOSE:
            DestroyWindow (hwnd);
            break;

        case WM_DESTROY:
            PostQuitMessage (0);
            break;

        default:
            return DefWindowProc (hwnd, msg, wParam, lParam);
    }

    return 0;
}

LRESULT CALLBACK eMessageWndProc (HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
        case WM_KEYDOWN:
            if ((int) wParam == VK_RETURN)
                SendMessage();
        break;
    }

    return CallWindowProc (OldeMessageWndProc, hwnd, msg, wParam, lParam);
}
