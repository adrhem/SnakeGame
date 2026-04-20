// ********************************************************************* //
// *                                                                   * //
// *                                          Copyright (c) 2017/2022  * //
// *                                                                   * //
// * Clone library based on conio.h from Borland company for           * //
// * compiler Turbo C++ 3.0 and from Embacadero company for compiler   * //
// * Embarcadero C++ 10.2 'Tokyo'.                                     * //
// *                                                                   * //
// * Project ..........: conio_am.h                                    * //
// * Managed by .......: Jose Augusto N. G. Manzano                    * //
// * Also Known As ....: Augusto Manzano                               * //
// * Build Date  ......: 2018, June                                    * //
// * Version  .........: 7.1.22.12 - prealpha                          * //
// *                                                                   * //
// * For public domain without any warranty.                           * //
// *                                                                   * //
// * Collaborating programmers (in order of collaboration)             * //
// * =====================================================             * //
// *                                                                   * //
// * (BRA) Victor Carlquist                                            * //
// * (BRA) Rodrigo Messias da Silva                                    * //
// * (BRA) Lucas Ventura Moura Alves                                   * //
// *                                                                   * //
// * Collaborating co-authors (in order of collaboration)              * //
// * ====================================================              * //
// *                                                                   * //
// * (your country here) your name here                                * //
// *                                                                   * //
// * Constraint                                                        * //
// * ==========                                                        * //
// *                                                                   * //
// * The functions described here operate within the screen limit of   * //
// * 80 columns and 25 rows. For other sizes only after the basic set  * //
// * of implemented functions.                                         * //
// *                                                                   * //
// ********************************************************************* //
//
// Format version ..: [number.edit.year.month]
//
// Number change ...: When it has new functionality.
// Edit changes ....: When there are any changes in the functionalities.
// Year change .....: Year when any change occurs.
// Month change ....: Month when any change occurs.
//
// Functions (conio.h in conio_am.h)
// Compatible with Turbo C++ and Embarcadero C++
//
// _setcursortype   implemented
// cgets		  	    implemented
// clreol		  	    implemented
// clrscr		  	    implemented
// cprintf		    	implemented
// cputs		      	implemented
// cscanf			      implemented
// delline          implemented
// getch			      implemented
// getche			      implemented
// getpass			    implemented
// gettext          not implemented
// gettextinfo      not implemented
// gotoxy			      implemented
// highvideo		    implemented
// insline          implemented
// kbhit		  	    implemented
// lowvideo		     	implemented
// movetext         not implemented
// normvideo		    implemented
// putch		  	    implemented
// puttext          not implemented
// textattr			    implemented
// textbackground	  implemented
// textcolor		    implemented
// textmode         not implemented
// ungetch			    implemented
// wherex	    		  implemented
// wherey		        implemented
// window           not implemented
//
// Does not exist on the Embarcadero C++ (not implemented)
//
// inp          | These functions are 
// inport       | not implemented 
// inportb      | because they are not 
// inpw         | executed within
// outp         | Windows.
// outport
// outportb
// outpw
//
// Constants, enums and structs defineds (adapted).
//
// - BLINK			Defined, but not in use.
// - COLORS			Is functional.
// - _NOCURSOR		Is functional.
// - _NORMALCURSOR	Is functional.
// - _SOLIDCURSOR	Is functional.
// - _text_info		Defined, but not in use.
// - _text_modes	Defined, but not in use.
// - _wscroll		Is not functional.
//
// Reference
//
// Turbo C Reference Guide
// Version 2.0 - 1988
// Borland Internacional
// 1800 Green Hills Road
// Scotts Valley, CA 95066-00001
//
// Turbo C++ Library Reference
// Version 3.1 - 1993
// Borland Internacional
// 1800 Green Hills Road
// Scotts Valley, CA 95066-00001
//
// Turbo C++ Library Reference
// Version 4.0 - 1993
// Borland Internacional
// 100 Borland Way
// Scotts Valley, CA 95067-3249
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED
// WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#ifndef _CONIO_AM_H_
  #define _CONIO_AM_H_
  #include "conio_am.h"
  #include <cctype>
  #include <cstdarg>
  #include <cstdio>
  #include <cstdlib>
  #include <cstring>
  #include <iostream>
  #if defined _WIN32 || defined _WIN64
    #include <windows.h>
  #else
    #include <fcntl.h>
    #include <termios.h>
    #include <unistd.h>
  #endif

  // ********************************************************************* //
  // *                                                                   * //
  // * General constants, structs and enums to support the library and   * //
  // * more.                                                             * //
  // *                                                                   * //
  // ********************************************************************* //

  // General constants.

  #define _NOCURSOR       0  // turns off the cursor.
  #define _SOLIDCURSOR    1  // solid block cursor.
  #define _NORMALCURSOR   2  // normal underscore cursor (only Windows).
  #define _wscroll        1
  #define BLINK         128  // BLINK mode for textcolor (not operation).

  // Keys Control.

  #if defined _WIN32 || defined _WIN64
    #define ENTER '\r' // Key <Enter> for Windows
    #define BACK     8 // Key <Backspace>
  #else
    #define ENTER '\n' // Key <Enter> for Linux/Mac OS X
    #define BACK   127 // Key <Backspace> (<Delete>)
  #endif

  // COLORS - text mode.
  // Text and background colors from 0 to 7.
  // Colors are for text from 8 to 15.

  enum COLORS
  {
    BLACK        =  0,
    BLUE         =  1,
    GREEN        =  2,
    CYAN         =  3,
    RED          =  4,
    MAGENTA      =  5,
    BROWN        =  6,
    LIGHTGRAY    =  7,
    DARKGRAY     =  8,
    LIGHTBLUE    =  9,
    LIGHTGREEN   = 10,
    LIGHTCYAN    = 11,
    LIGHTRED     = 12,
    LIGHTMAGENTA = 13,
    YELLOW       = 14,
    WHITE        = 15,
  };

  // Text information with values standard Borland.
  
  struct text_info
  {
    unsigned int winleft      =  1;
    unsigned int wintop       =  1;
    unsigned int winright     = 80;
    unsigned int winbottom    = 25;
    unsigned int attribute    =  7;
    unsigned int normattr     =  7;
    unsigned int currmode     =  3;
    unsigned int screenheight = 25;
    unsigned int screenwidth  = 80;
    unsigned int curx         =  1;
    unsigned int cury         =  1;
    unsigned int flag         =  0;
  };

  // The INF_TEXTUAL support functions:
  // - delline
  // - insline

  text_info INF_TEXTUAL;
  
  // Text modes with values standard Borland.

  enum text_modes
  {
    EXITMODE  = -2,
    LASTMODE  = -1,
    BW40      =  0,
    C40       =  1,
    BW80      =  2,
    C80       =  3,
    MONO      =  7,
    C40X14    =  8,
    C40X21    =  9,
    C40X28    = 10,
    C40X43    = 11,
    C40X50    = 12,
    C40X60    = 13,
    C80X14    = 14,
    C80X21    = 15,
    C80X28    = 16,
    C80X43    = 17,
    C80X50    = 18,
    C80X60    = 19,
    BW40X14   = 20,
    BW40X21   = 21,
    BW40X28   = 22,
    BW40X43   = 23,
    BW40X50   = 24,
    BW40X60   = 25,
    BW80X14   = 26,
    BW80X21   = 27,
    BW80X28   = 28,
    BW80X43   = 29,
    BW80X50   = 30,
    BW80X60   = 31,
    MONO14    = 32, // Invalid VGA mode
    MONO21    = 33,
    MONO28    = 34,
    MONO43    = 35,
    MONO50    = 36,
    MONO60    = 37,
    C4350     = 64,
    _ORIGMODE = 65  // original mode at program startup
  };
  
  // The ungetch function needs the flag to know if the buffer has been
  // changed, but, not all input functions change the flag's value.
  // The ENTRADA_REALIZADA can be set by the following functions:
  // - cputs
  // - getch
  // - getche
  // By: Victor Carlquist

  static bool ENTRADA_REALIZADA = true;

  // ********************************************************************* //
  // *                                                                   * //
  // * General and support functions for the library not belonging to    * //
  // * the conio library.                                                * //
  // *                                                                   * //
  // * - delay                                                           * //
  // * - gcurs                                                           * //
  // * - itoav (clobe of itoa)                                           * //
  // * - ltoav (clone of ltoa)                                           * //
  // * - sleep (only Windows)                                            * //
  // *                                                                   * //
  // ********************************************************************* //

  void   delay(unsigned int MILISSEGUNDOS);
  void   gcurs(int *COLUNA, int *LINHA);
  char   *itoav(int VLR_DECIMAL, char *CADEIA, unsigned short BASE);
  char   *ltoav(long VLR_DECIMAL, char *CADEIA, short BASE);
  #if defined _WIN32 || defined _WIN64
    void sleep(unsigned int SEGUNDOS);
  #endif

  // ********************************************************************* //
  // *                                                                   * //
  // * Library features implemented: Turbo C++ CONIO (22/30).            * //
  // *                                                                   * //
  // ********************************************************************* //

  void    _setcursortype(short TIPO);
  char   *cgets(char *CADEIA);
  void    clreol(void);
  void    clrscr(void);
  int     cprintf(const char *FORMATO, ...);
  int     cputs(const char *CADEIA);
  int     cscanf(const char *FORMATO, ...);
  void    delline(void);
  char    getch(void);
  char    getche(void);
  char   *getpass(const char *MENSAGEM);
  //      gettext
  //      gettextinfo
  void    gotoxy(int COLUNA, int LINHA);
  void    highvideo(void);
  void    insline(void);
  int     kbhit(void);
  void    lowvideo(void);
  //      movetext
  void    normvideo(void);
  int     putch(const char CARACTERE);
  //      puttext
  void    textattr(int ATRIBUTO);
  void    textbackground(int COR);
  void    textcolor(int COR);
  //      textmode
  int     ungetch(char TECLA);
  int     wherex(void);
  int     wherey(void);
  //      window

  // * .x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x. * //
  // * .x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x. * //

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: delay()                                      * //
  // *                                                                   * //
  // * Author review......: Victor Carlquist                             * //
  // * Review date  ......: 2017.03.13                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void delay(unsigned int MILISSEGUNDOS)
  {
    #if defined _WIN32 || defined _WIN64
      Sleep(MILISSEGUNDOS);
    #else
      sleep(MILISSEGUNDOS / 1000);
    #endif
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: gcurs()                                      * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2021.05.17                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void gcurs(int *COLUNA, int *LINHA)
  {
    #if defined _WIN64 || defined _WIN32
      HANDLE CONSOLE;
      CONSOLE_SCREEN_BUFFER_INFO VIDEO;
      CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
      GetConsoleScreenBufferInfo(CONSOLE, &VIDEO);
      *COLUNA = VIDEO.dwCursorPosition.X + 1;
      *LINHA  = VIDEO.dwCursorPosition.Y + 1;
    #else
      termios ESCRITA, TECLADO;
      tcgetattr(STDIN_FILENO, &ESCRITA);
      TECLADO = ESCRITA;
      TECLADO.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &TECLADO);
      printf("\033[6n");
      fflush(stdout);
      scanf("\033[%i;%iR", LINHA, COLUNA);
      tcsetattr(STDIN_FILENO, TCSADRAIN, &ESCRITA);
    #endif
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: itoav()                                      * //
  // *                                                                   * //
  // * Author review......:                                              * //
  // * Review date  ......:                                              * //
  // * Version review.....:                                              * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  char *itoav(int VLR_DECIMAL, char *CADEIA, unsigned short BASE)
  {
    char X, *I = 0, *J = 0, *PCADEIA = CADEIA;
    unsigned int VALOR;
    char DIGITOS[] =
      {
        '0', '1', '2', '3', '4', '5', '6', '7', '8',
        '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
        'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
      };
    VALOR = (VLR_DECIMAL < 0 and BASE == 10) ? -VLR_DECIMAL : (unsigned int) VLR_DECIMAL;
    if (BASE < 2 or BASE > 62)
      {
        *PCADEIA++ = ' ';
        *PCADEIA = '\0';
        return CADEIA;
      }
    while (VALOR >= BASE)
      {
        *PCADEIA++ = DIGITOS[VALOR % BASE];
        VALOR /= BASE;
      }
    *PCADEIA++ = DIGITOS[VALOR];
    if (VLR_DECIMAL < 0 and BASE == 10)
      {
        *PCADEIA++ = '-';
      }
    *PCADEIA = '\0';
    J = strlen(CADEIA) + CADEIA - 1;
    for (I = CADEIA; I < J; ++I)
      {
        X = *I, *I = *J, *J = X, --J;
      }
    return CADEIA;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: ltoav()                                      * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2021.05.14                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  char *ltoav(long VLR_DECIMAL, char *CADEIA, short BASE)
  {
    char X, *I = 0, *J = 0, *PCADEIA = CADEIA;
    unsigned long VALOR;
    char DIGITOS[] =
      {
        '0', '1', '2', '3', '4', '5', '6', '7', '8',
        '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
        'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
        'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
        'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
        's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
      };
    VALOR = (VLR_DECIMAL < 0 and BASE == 10) ? -VLR_DECIMAL : (unsigned long) VLR_DECIMAL;
    if (BASE < 2 or BASE > 62)
      {
        *PCADEIA++ = ' ';
        *PCADEIA = '\0';
        return CADEIA;
      }
    while (VALOR >= (unsigned)BASE)
      {
        *PCADEIA++ = DIGITOS[VALOR % BASE];
        VALOR /= BASE;
      }
    *PCADEIA++ = DIGITOS[VALOR];
    if (VLR_DECIMAL < 0 and BASE == 10)
      {
        *PCADEIA++ = '-';
      }
    *PCADEIA = '\0';
    J = strlen(CADEIA) + CADEIA - 1;
    for (I = CADEIA; I < J; ++I)
      {
        X = *I, *I = *J, *J = X, --J;
      }
    return CADEIA;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: sleep()                                      * //
  // *                                                                   * //
  // * Author review......:                                              * //
  // * Review date  ......:                                              * //
  // * Version review.....:                                              * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  #if defined _WIN64 || defined _WIN32
    void sleep(unsigned int SEGUNDOS)
    {
      delay(SEGUNDOS * 1000);
      return;
    }
  #endif

  // * .x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x. * //
  // * .x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x.x. * //

  // ********************************************************************* //
  // *                                                                   * //
  // * Supporting features: conio_am-h library.                          * //
  // *                                                                   * //
  // ********************************************************************* //

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: cgets()                                      * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2021.05.14                                   * //
  // * Version review.....: 1.3                                          * //
  // * Author review......: Victor Carlquist                             * //
  // * Review date  ......: 2017.03.22                                   * //
  // * Version review.....: 1.2                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.19                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  char *cgets(char *CADEIA)
  {
    char ENTRADA = '\0';
    ENTRADA_REALIZADA = true;
    unsigned int I = 2;
    while (I <= (unsigned)CADEIA[0] + 1)
      {
        ENTRADA = getch();
        if (ENTRADA != ENTER && I <= (unsigned int)CADEIA[0])
          {
            if (ENTRADA == BACK && I == 2) {} // Prevent BS before entry
            if (isprint(ENTRADA))
              {
                putch(ENTRADA);
                CADEIA[I] = ENTRADA;
                ++I;
              }
            if (ENTRADA == BACK && I > 2)
              {
                std::cout << "\b \b";
                CADEIA[I] = '\0';
                --I;
              }
           }
        else
          {
            CADEIA[I] = '\0';
            CADEIA[1] = (char) I - 2;
            I = CADEIA[0] + 2;
          }
      }
    return &CADEIA[2];
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: clreol()                                     * //
  // *                                                                   * //
  // * Author review......:                                              * //
  // * Review date  ......:                                              * //
  // * Version review.....:                                              * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void clreol(void)
  {
    #if defined _WIN64 || defined _WIN32
      HANDLE CONSOLE;
      COORD POSICAO;
      CONSOLE_SCREEN_BUFFER_INFO VIDEO;
      DWORD ESCRITA = 0;
      CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
      GetConsoleScreenBufferInfo(CONSOLE, &VIDEO);
      POSICAO.X = VIDEO.dwCursorPosition.X;
      POSICAO.Y = VIDEO.dwCursorPosition.Y;
      FillConsoleOutputCharacter(CONSOLE, 32, 80 - POSICAO.X , POSICAO, &ESCRITA);
    #else
      std::cout << "\033[K";
    #endif
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: clrscr()                                     * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.14                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void clrscr(void)
  {
    #if defined _WIN64 || defined _WIN32
      HANDLE TELA;
      COORD POSICAO;
      DWORD ESCRITA = 0;
      TELA = GetStdHandle(STD_OUTPUT_HANDLE);
      POSICAO.X = 0;
      POSICAO.Y = 0;
      FillConsoleOutputCharacter(TELA, 32, 80 * 25, POSICAO, &ESCRITA);
      SetConsoleCursorPosition(TELA, POSICAO);
    #else
      std::cout << "\033[2J\033[1;1f";
    #endif
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: cprintf()                                    * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.19                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.17                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  int cprintf(const char *FORMATO, ...)
  {
    char *VIDEO;
    va_list ARGUMENTOS;
    int CARACTERES;
    VIDEO = (char*)malloc(1024);
    va_start(ARGUMENTOS, FORMATO);
    CARACTERES = vsprintf(VIDEO, FORMATO, ARGUMENTOS);
    cputs(VIDEO);
    va_end(ARGUMENTOS);
    free(VIDEO);
    if (CARACTERES == EOF)
      {
        return EOF;
      }
    else
      {
        return CARACTERES;
      }
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: cputs()                                      * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2021.05.14                                   * //
  // * Version review.....: 3.1                                          * //
  // * Author review......: Rodrigo Messias da Silva                     * //
  // * Review date  ......: 2017.06.14                                   * //
  // * Version review.....: 3.0                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.25                                   * //
  // * Version review.....: 2.0                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.15                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.14                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  int cputs(const char *CADEIA)
  {
    unsigned int POSICAO;
    char CARACTERE;
    if (*CADEIA == EOF)
      {
        return EOF;
      }
    else
      {
        POSICAO = 0;
        while (POSICAO <= (unsigned)strlen(CADEIA) - 1)
          {
            CARACTERE = CADEIA[POSICAO];
            switch (CARACTERE)
              {
                case '\n': gotoxy(wherex(), wherey() + 1); break;
                case '\t': CARACTERE = CADEIA[++POSICAO];  break;
              }
            if (CARACTERE != '\n')
              {
                std::cout << CARACTERE;
			        }
            ++POSICAO;
          }
        return strlen(CADEIA);
      }
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: cscanf()                                     * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2018.06.21                                   * //
  // * Version review.....: 1.3                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.25                                   * //
  // * Version review.....: 1.2                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.19                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.17                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  int cscanf(const char *FORMATO, ...)
  {
    int  CARACTERES;
    va_list ARGUMENTOS;
    va_start(ARGUMENTOS, FORMATO);
    CARACTERES = vfscanf(stdin, FORMATO, ARGUMENTOS);
    va_end(ARGUMENTOS);
    if (strncmp(FORMATO, "", 0) == 0)
     {
        return 0;
      }
    if (CARACTERES == EOF)
      {
        return EOF;
      }
    else
      {
        return CARACTERES;
      }
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: delline()                                    * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2021.05.24                                   * //
  // * Version review.....: 1.1 (adapted)                                * //
  // * Author ............: Demidov Andrey                               * //
	// * Published .........: sourceforge.net/projects/coniow)             * //
  // * Date ..............: 2015.10.31                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void delline(void)
  {
    #if defined _WIN32 || defined _WIN64
      CHAR_INFO CARACTERE;
      CONSOLE_SCREEN_BUFFER_INFO VIDEO;
      COORD POSICAO;
      DWORD ESCRITA;
      SMALL_RECT TELA;
      UINT PAGINA_CODIGO_ANSI;
      int I;
      if (INF_TEXTUAL.flag)
        {
          return;
        }
      INF_TEXTUAL.flag = 1;
      for (I = 0; I <= 1; ++I)
        {
          if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &VIDEO))
            {
              break;
            }
          if (I)
            {
              return;
            }
          FreeConsole();
          AllocConsole();
        }
      INF_TEXTUAL.winright     = VIDEO.dwSize.X;
      INF_TEXTUAL.winbottom    = VIDEO.dwSize.Y;
      INF_TEXTUAL.attribute    = VIDEO.wAttributes;
      INF_TEXTUAL.normattr     = VIDEO.wAttributes;
      INF_TEXTUAL.screenheight = VIDEO.dwSize.Y;
      INF_TEXTUAL.screenwidth  = VIDEO.dwSize.X;
      INF_TEXTUAL.curx         = VIDEO.dwCursorPosition.X + 1;
      INF_TEXTUAL.cury         = VIDEO.dwCursorPosition.Y + 1;
      PAGINA_CODIGO_ANSI = GetACP();
      if (GetConsoleOutputCP() != PAGINA_CODIGO_ANSI)
        {
          SetConsoleOutputCP(PAGINA_CODIGO_ANSI);
          SetConsoleCP(PAGINA_CODIGO_ANSI);
        }
      GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &ESCRITA);
      SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ESCRITA | ENABLE_WINDOW_INPUT
                                                             | ENABLE_MOUSE_INPUT
                                                             | ENABLE_ECHO_INPUT);
      TELA.Left                  = INF_TEXTUAL.winleft   - 1;
      TELA.Top                   = INF_TEXTUAL.wintop    - 1 + INF_TEXTUAL.cury;
      TELA.Right                 = INF_TEXTUAL.winright  - 1;
      TELA.Bottom                = INF_TEXTUAL.winbottom - 1;
      POSICAO.X                  = INF_TEXTUAL.winleft   - 1;
      POSICAO.Y                  = INF_TEXTUAL.wintop    - 1 + INF_TEXTUAL.cury - 1;
      CARACTERE.Char.UnicodeChar = L' ';
      CARACTERE.Attributes       = INF_TEXTUAL.attribute;
      ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE), &TELA, NULL, POSICAO, &CARACTERE);
      gotoxy (INF_TEXTUAL.curx, INF_TEXTUAL.cury);
    #else
      printf("\033[1M");
    #endif
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: getch()                                      * //
  // *                                                                   * //
  // * Author review......: Victor Carlquist                             * //
  // * Review date  ......: 2017.03.22                                   * //
  // * Version review.....: 1.2                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.19                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  char getch(void)
  {
    ENTRADA_REALIZADA = true;
    #if defined _WIN32 || defined _WIN64
      char CARACTERE;
      HANDLE CONSOLE;
      DWORD ESCRITA = 0, NUMCARAC;
      CONSOLE = GetStdHandle(STD_INPUT_HANDLE);
      GetConsoleMode(CONSOLE, &ESCRITA);
      SetConsoleMode(CONSOLE, ESCRITA  & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));
      ReadConsole(CONSOLE, &CARACTERE, 1, &NUMCARAC, NULL);
      SetConsoleMode(CONSOLE, ESCRITA);
      return CARACTERE;
    #else
      int CARACTERE;
      termios ESCRITA, TECLADO;
      tcgetattr(STDIN_FILENO, &ESCRITA);
      TECLADO = ESCRITA;
      TECLADO.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &TECLADO);
      CARACTERE = getchar();
      tcsetattr(STDIN_FILENO, TCSANOW, &ESCRITA);
      return (char)CARACTERE;
    #endif
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: getche()                                     * //
  // *                                                                   * //
  // * Author review......: Victor Carlquist                             * //
  // * Review date  ......: 2017.03.22                                   * //
  // * Version review.....: 1.2                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.19                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  char getche(void)
  {
    ENTRADA_REALIZADA = true;
    #if defined _WIN32 || defined _WIN64
      char CARACTERE;
      HANDLE CONSOLE;
      DWORD ESCRITA = 0, NUMCARAC;
      CONSOLE = GetStdHandle(STD_INPUT_HANDLE);
      GetConsoleMode(CONSOLE, &ESCRITA);
      SetConsoleMode(CONSOLE, ESCRITA  & ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT));
      ReadConsole(CONSOLE, &CARACTERE, 1, &NUMCARAC, NULL);
      SetConsoleMode(CONSOLE, ESCRITA);
      std::cout << CARACTERE;
      return CARACTERE;
    #else
      termios ESCRITA, TECLADO;
      int CARACTERE;
      tcgetattr(STDIN_FILENO, &ESCRITA);
      TECLADO = ESCRITA;
      TECLADO.c_lflag &= ~(ICANON);
      tcsetattr(STDIN_FILENO, TCSANOW, &TECLADO);
      CARACTERE = getchar();
      tcsetattr(STDIN_FILENO, TCSANOW, &ESCRITA);
      return (char)CARACTERE;
    #endif
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: getpass()                                    * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2021.05.14                                   * //
  // * Version review.....: 1.2                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.19                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  char *getpass(const char *MENSAGEM)
  {
    char ENTRADA = '\0';
    static char SENHA[10];
    unsigned int I = 2;
    *SENHA = 8;
    std::cout << MENSAGEM;
    while (I <= (unsigned int)SENHA[0] + 1)
      {
        ENTRADA = getch();
        if (ENTRADA != ENTER)
          {
            if (isprint(ENTRADA))
              {
                SENHA[I] = ENTRADA;
                ++I;
              }
            else
              if (ENTRADA == BACK && I != 0)
                {
                  SENHA[I] = '\0';
                  --I;
                }
          }
        else
          {
            SENHA[I] = '\0';
            SENHA[1] = (char) I - 2;
            I = SENHA[0] + 2;
          }
      }
    SENHA[2 + (int) SENHA[1]] = 0;
    return &SENHA[2];
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: gotoxy()                                     * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.22                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void gotoxy(int COLUNA, int LINHA)
  {
    #if defined _WIN64 || defined _WIN32
      HANDLE TELA;
      COORD POSICAO;
      TELA = GetStdHandle(STD_OUTPUT_HANDLE);
      if (COLUNA >= 1 && COLUNA <= 80 && LINHA >= 1 && LINHA <= 25)
        {
          POSICAO.X = COLUNA - 1;
          POSICAO.Y = LINHA  - 1;
        }
      else
        {
          POSICAO.X = 0;
          POSICAO.Y = 0;
        }
      SetConsoleCursorPosition(TELA, POSICAO);
    #else
      if (COLUNA >= 1 && COLUNA <= 80 && LINHA >= 1 && LINHA <= 25)
        {
          std::cout << "\033[" << LINHA << ";" << COLUNA << "H";
        }
      else
        {
          std::cout << "\033[0;0H";
        }
    #endif
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: highvideo()                                  * //
  // *                                                                   * //
  // * Author review......:                                              * //
  // * Review date  ......:                                              * //
  // * Version review.....:                                              * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void highvideo(void)
  {
    #if defined _WIN64 || defined _WIN32
      HANDLE CONSOLE;
      CONSOLE_SCREEN_BUFFER_INFO VIDEO;
      CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
      GetConsoleScreenBufferInfo(CONSOLE, &VIDEO);
      SetConsoleTextAttribute(CONSOLE, (VIDEO.wAttributes | FOREGROUND_INTENSITY));
    #else
      std::cout << "\033[1m";
    #endif
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: insline()                                    * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2021.05.24                                   * //
  // * Version review.....: 1.1 (adapted)                                * //
  // * Author ............: Demidov Andrey                               * //
	// * Published .........: sourceforge.net/projects/coniow)             * //
  // * Date ..............: 2015.10.31                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void insline(void)
  {
    #if defined _WIN32 || defined _WIN64
      CHAR_INFO CARACTERE;
      CONSOLE_SCREEN_BUFFER_INFO VIDEO;
      COORD POSICAO;
      DWORD ESCRITA;
      SMALL_RECT TELA;
      UINT PAGINA_CODIGO_ANSI;
      int I;
      if (INF_TEXTUAL.flag) 
	      {
          return;
        }
      INF_TEXTUAL.flag = 1;
      for (I = 0; I <= 1; ++I)
        {
          if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &VIDEO)) 
            {
              break;
            }
          if (I) 
            {
              return;
            }
          FreeConsole();
          AllocConsole();
        }
      INF_TEXTUAL.winright     = VIDEO.dwSize.X;
      INF_TEXTUAL.winbottom    = VIDEO.dwSize.Y;
      INF_TEXTUAL.attribute    = VIDEO.wAttributes;
      INF_TEXTUAL.normattr     = VIDEO.wAttributes;
      INF_TEXTUAL.screenheight = VIDEO.dwSize.Y;
      INF_TEXTUAL.screenwidth  = VIDEO.dwSize.X;
      INF_TEXTUAL.curx         = VIDEO.dwCursorPosition.X + 1;
      INF_TEXTUAL.cury         = VIDEO.dwCursorPosition.Y + 1;
      PAGINA_CODIGO_ANSI = GetACP();
      if (GetConsoleOutputCP() != PAGINA_CODIGO_ANSI)
        {
          SetConsoleOutputCP(PAGINA_CODIGO_ANSI);
          SetConsoleCP(PAGINA_CODIGO_ANSI);
        }
      GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &ESCRITA);
      SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ESCRITA | ENABLE_WINDOW_INPUT
                                                             | ENABLE_MOUSE_INPUT
                                                             | ENABLE_ECHO_INPUT); 
      TELA.Left                  = INF_TEXTUAL.winleft   - 1;
      TELA.Top                   = INF_TEXTUAL.wintop    - 1 + INF_TEXTUAL.cury - 1;
      TELA.Right                 = INF_TEXTUAL.winright  - 1;
      TELA.Bottom                = INF_TEXTUAL.winbottom - 2;
      POSICAO.X                  = INF_TEXTUAL.winleft   - 1;
      POSICAO.Y                  = INF_TEXTUAL.wintop    - 1 + INF_TEXTUAL.cury;
      CARACTERE.Attributes       = INF_TEXTUAL.attribute;
      CARACTERE.Char.UnicodeChar = L' ';
      ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE), &TELA, NULL, POSICAO, &CARACTERE);
      gotoxy (INF_TEXTUAL.curx, INF_TEXTUAL.cury);
    #else
      printf("\033[1L");
    #endif
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: kbhit()                                      * //
  // *                                                                   * //
  // * Author review......:                                              * //
  // * Review date  ......:                                              * //
  // * Version review.....:                                              * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  int kbhit(void)
  {
    char CARACTERE;
    do
      {
        CARACTERE = getch();
        if (CARACTERE != EOF)
          {
            ungetc(CARACTERE, stdin);
            return 1;
          }
      }
    while (true);
    return 0;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: lowvideo()                                   * //
  // *                                                                   * //
  // * Author review......:                                              * //
  // * Review date  ......:                                              * //
  // * Version review.....:                                              * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void lowvideo(void)
  {
    #if defined _WIN64 || defined _WIN32
      HANDLE CONSOLE;
      CONSOLE_SCREEN_BUFFER_INFO VIDEO;
      CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
      GetConsoleScreenBufferInfo(CONSOLE, &VIDEO);
      SetConsoleTextAttribute(CONSOLE, VIDEO.wAttributes & 0x08);
    #else
      std::cout << "\033[2m";
    #endif
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: normvideo()                                  * //
  // *                                                                   * //
  // * Author review......:                                              * //
  // * Review date  ......:                                              * //
  // * Version review.....:                                              * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void normvideo(void)
  {
    #if defined _WIN64 || defined _WIN32
      HANDLE CONSOLE;
      CONSOLE_SCREEN_BUFFER_INFO VIDEO;
      CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
      GetConsoleScreenBufferInfo(CONSOLE, &VIDEO);
      SetConsoleTextAttribute(CONSOLE, 0x07);
    #else
      std::cout << "\033[0m";
    #endif
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: putch()                                      * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2018.06.18                                   * //
  // * Version review.....: 1.3                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.22                                   * //
  // * Version review.....: 1.2                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.19                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.13                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  int putch(const char CARACTERE)
  {
    if ((int)CARACTERE == BACK)
      {
        std::cout << "\b";
      }
    else
      {
        if (isascii(CARACTERE))
          {
            std::cout << CARACTERE;
          }
        else
          {
        	return EOF;
          }
	  }
    return (int)CARACTERE;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: _setcursortype()                             * //
  // *                                                                   * //
  // * Author review......: Lucas Ventura Moura Alves                    * //
  // * Review date  ......: 2018.06.21                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.15                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void _setcursortype(short TIPO)
  {

    #if defined _WIN32 || defined _WIN64
      HANDLE CONSOLE;
      CONSOLE_CURSOR_INFO CURSOR;
      CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
      switch(TIPO)
        {
           case _NOCURSOR:     CURSOR.dwSize = 100; CURSOR.bVisible = FALSE; break;
           case _SOLIDCURSOR:  CURSOR.dwSize = 100; CURSOR.bVisible = TRUE;  break;
           case _NORMALCURSOR: CURSOR.dwSize =  10; CURSOR.bVisible = TRUE;  break;
        }
      SetConsoleCursorInfo(CONSOLE, &CURSOR);
    #else
      switch(TIPO)
        {
           case _NOCURSOR:     std::cout << "\033[?25l";         break;
           case _SOLIDCURSOR:  std::cout << "\033[1 q\033[?25h"; break;
           case _NORMALCURSOR: std::cout << "\033[3 q\033[?25h"; break;
        }
    #endif
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: textattr()                                   * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.22                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.15                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void textattr(int ATRIBUTO)
  {
    textbackground(ATRIBUTO / 16);
    textcolor(ATRIBUTO % 16);
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: textbackground()                             * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.22                                   * //
  // * Version review.....: 1.2                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.13                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void textbackground(int COR)
  {
    if (COR >= 0 && COR <= 7)
      {
        #if defined _WIN64 || defined _WIN32
          HANDLE CONSOLE;
          CONSOLE_SCREEN_BUFFER_INFO VIDEO;
          CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
          GetConsoleScreenBufferInfo(CONSOLE, &VIDEO);
          SetConsoleTextAttribute(CONSOLE, (VIDEO.wAttributes & 0x0F) | (COR << 4));
        #else
          if (COR >= 0 && COR <= 7)
            {
              switch (COR)
                {
                  case  0: std::cout << "\033[40m"; break; // Preto
                  case  1: std::cout << "\033[44m"; break; // Azul
                  case  2: std::cout << "\033[42m"; break; // Verde
                  case  3: std::cout << "\033[46m"; break; // Ciano
                  case  4: std::cout << "\033[41m"; break; // Vermelho
                  case  5: std::cout << "\033[45m"; break; // Magenta
                  case  6: std::cout << "\033[43m"; break; // Marrom
                  case  7: std::cout << "\033[47m"; break; // Cinza claro
                }
            }
        #endif
      }
    else
      {
        normvideo();
      }
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: textcolor()                                  * //
  // *                                                                   * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.22                                   * //
  // * Version review.....: 1.2                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.22                                   * //
  // * Version review.....: 1.1                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  void textcolor(int COR)
  {
    if (COR >= 0 && COR <= 15)
      {
        #if defined _WIN64 || defined _WIN32
          HANDLE CONSOLE;
          CONSOLE_SCREEN_BUFFER_INFO VIDEO;
          CONSOLE = GetStdHandle(STD_OUTPUT_HANDLE);
          GetConsoleScreenBufferInfo(CONSOLE, &VIDEO);
          SetConsoleTextAttribute(CONSOLE, (VIDEO.wAttributes & 0xF0) | COR);
        #else
          if (COR >= 0 && COR <= 15)
            {
              switch (COR)
                {
                  case   0: std::cout << "\033[30m";   break; // Preto
                  case   1: std::cout << "\033[34m";   break; // Azul
                  case   2: std::cout << "\033[32m";   break; // Verde
                  case   3: std::cout << "\033[36m";   break; // Ciano
                  case   4: std::cout << "\033[31m";   break; // Vermelho
                  case   5: std::cout << "\033[35m";   break; // Magenta
                  case   6: std::cout << "\033[33m";   break; // Marrom
                  case   7: std::cout << "\033[37m";   break; // Cinza claro
                  case   8: std::cout << "\033[1;30m"; break; // Cinza escuro
                  case   9: std::cout << "\033[1;34m"; break; // Azul claro
                  case  10: std::cout << "\033[1;32m"; break; // Verde claro
                  case  11: std::cout << "\033[1;36m"; break; // Ciano claro
                  case  12: std::cout << "\033[1;31m"; break; // Vermelho claro
                  case  13: std::cout << "\033[1;35m"; break; // Magenta claro
                  case  14: std::cout << "\033[1;33m"; break; // Amarelo
                  case  15: std::cout << "\033[1;37m"; break; // Branco
                }
            }
        #endif
      }
    else
      {
        normvideo();
      }
    return;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: ungetch()                                    * //
  // *                                                                   * //
  // * Author review......: Victor Carlquist                             * //
  // * Review date  ......: 2017.03.22                                   * //
  // * Version review.....: 2.2                                          * //
  // * Author review......: José Augusto N. G. Manzano                   * //
  // * Review date  ......: 2017.03.21                                   * //
  // * Version review.....: 2.1                                          * //
  // * Author review......: Victor Carlquist                             * //
  // * Review date  ......: 2017.03.18                                   * //
  // * Version review.....: 2.0                                          * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.16                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  int ungetch(char TECLA)
  {
    if (ENTRADA_REALIZADA)
      {
        ENTRADA_REALIZADA = false;
        std::streambuf *TECLADO = std::cin.rdbuf();
        TECLADO->sputbackc(TECLA);
        std::cin.ignore();
        return TECLA;
      }
    else
      {
        return EOF;
      }
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: wherex()                                     * //
  // *                                                                   * //
  // * Author review......:                                              * //
  // * Review date  ......:                                              * //
  // * Version review.....:                                              * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  int wherex(void)
  {
    int COLUNA, LINHA;
    gcurs(&COLUNA, &LINHA);
    return COLUNA;
  }

  // ********************************************************************* //
  // *                                                                   * //
  // * Function ..........: wherey()                                     * //
  // *                                                                   * //
  // * Author review......:                                              * //
  // * Review date  ......:                                              * //
  // * Version review.....:                                              * //
  // * Author ............: José Augusto N. G. Manzano                   * //
  // * Date ..............: 2017.03.11                                   * //
  // * Version ...........: 1.0                                          * //
  // *                                                                   * //
  // ********************************************************************* //

  int wherey(void)
  {
    int COLUNA, LINHA;
    gcurs(&COLUNA, &LINHA);
    return LINHA;
  }

#endif //_CONIO_H_

// ********************************************************************* //
// *                                                                   * //
// * trecho com texto somente em português.                            * //
// * parte con el texto solamente en portugués.                        * //
// * part with text only in portuguese.                                * //
// *                                                                   * //
// ********************************************************************* //

// Funcionalidade: delay()
//
// OBS: O cálculo do interválo de tempo percorrido pode ser reali-
//      zado com o trecho de código a seguir com auxílio da bibli-
//      teca "ctime" para uso do tipo "clock_t" tanto no GCC para
//      Windows como POSIX:
/*
        clock_t TEMPO;
        TEMPO = MILISSEGUNDOS + clock();
        while (TEMPO > clock());
*/
//      A "winapi" (exclusiva S.O. Windows) permite realizar a
//      a ação de contagem de tempo com auxílio da bibliteca
//      "windows.h" para a função "GetTickCount()" com o trecho
//      de código seguinte:
/*
        unsigned TEMPO = GetTickCount();
        while ((GetTickCount() - TEMPO) < (unsigned) MILISSEGUNDOS);
*/
//      Os laços acima podem ser utilizados de maneira didática ou em
//      sistemas operacionais que não tenham suporte a função "sleep",
//      porque o laço deixa a CPU ocupada e desperdiça energia elé-
//      trica. Já a função "sleep" deixa o processo "dormindo" (não
//      sendo executado pela CPU), permitindo que o sistema escalone
//      outros processos em seu lugar (Victor Carlquist).


// Funcionalidade: kbhit()
//
// OBS: função aguardando desenvolvimento de rotina para sistema
//      operacional Window. No POSIX função OK, testada com exito
//      ainda não implementada.
//
//      Segue código funcional POSIX (não implementado). Esta ação
//      esta definida na funcionalidade "getc()".
/*
        int kbhit(void)
        {
          termios ESCRITA, TECLADO;
          int CARACTERE;
          int TECLA;
          tcgetattr(STDIN_FILENO, &ESCRITA);
          TECLADO = ESCRITA;
          TECLADO.c_lflag &= ~(ICANON | ECHO);
          tcsetattr(STDIN_FILENO, TCSANOW, &TECLADO);
          TECLA = fcntl(STDIN_FILENO, F_GETFL, 0);
          fcntl(STDIN_FILENO, F_SETFL, TECLA | O_NONBLOCK);
          CARACTERE = getchar();
          tcsetattr(STDIN_FILENO, TCSANOW, &ESCRITA);
          fcntl(STDIN_FILENO, F_SETFL, TECLA);
          if (CARACTERE != EOF)
          {
            ungetc(CARACTERE, stdin);
            return 1;
          }
          return 0;
        }
*/

// Funcionalidade: ungetch()
//
// OBS: Apresentada nova versão. Mantida a versão 1.0 como
//      referência de estudo. Segue cóodigo:
/*
        int ungetch(char TECLA)
        {
          if (isascii(TECLA))
            {
              return TECLA - 48;
            }
          else
            {
              return EOF;
            }
        }
*/
//      A versão 2.0 da funcionalidade corresponde ao
//      código:
/*
        int ungetch(char TECLA)
        { // TECLADO = buffer
          std::streambuf *TECLADO = std::cin.rdbuf();
          TECLADO->sputbackc(TECLA);
          return 0;
        }
*/
//      A operação da funcionalidade ungetch pode
//      ser conseguida com o código adaptado de
//      K&R (simulação da ação):
/*
        int ungetch(char CARACTERE)
        {
          char TECLADO[100];
          int I = 0;
          if (I >= 100)
            {
               return EOF;
            }
          else
            {
              return TECLADO[I++] = CARACTERE - 48;
            }
        }
*/

// Funcionalidade: cputs()
//
// OBS: Apresentada em 03 de maio de 2017 versão funcional da
//      funcionalidade identificando a ação do código de contro-
//      le "\n" de forma adequada. Por conseguinte a funcionali-
//      dade "cprintf" que se utiliza de cputs passou a operar
//      corretamente.
//
// Nos compiladores Borland/Enbarcadero C++ a função "cputs" quando
// identifica o uso do código "\t" apresenta no seu local o caractere
// ASCII 248 existente exclusivamente para computadores padrão IBM PC
// no modo console (MS-DOS). A versão apresentada nesta biblioteca no
// local onde há a presennça do código "\n" não apresenta nada apenas
// desconsiderando a existência do código.
//
// O programador Victor apresentou um código alternativo muito interes-
// sante que pode ser usado em substituição ao código "cputs" incorpo-
// rado nesta biblioteca.
//
/*  int cputs(const char *CADEIA)
    {
      const char* INICIO = CADEIA;
      const char* FIM = CADEIA + strlen(CADEIA);
      if (*CADEIA == EOF)
        return EOF;
      while (INICIO != FIM)
        {
          if (*INICIO == '\n')
            gotoxy(wherex(), wherey() + 1);
          else if (*INICIO != '\t')
            std::cout << *INICIO;
          INICIO++;
        }
      return strlen(CADEIA);
    }
*/
