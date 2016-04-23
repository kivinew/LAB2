<<<<<<< HEAD
Ôªø#include "comPlex.h"

int Complex::counter;
int Complex::num;
double const Complex::pi = 3.1415926536;

Complex::Complex(): real(0), image(0)                                   // –∫–æ–Ω—Å—Ç—Ä—É–∫—Ç–æ—Ä –ø–æ —É–º–æ–ª—á–∞–Ω–∏—é
{
    objNum = ++num;
    ++counter;
}

Complex::Complex(int re, int im): real(re), image(im)                   // –∫–æ–Ω—Å—Ç—Ä—É–∫—Ç–æ—Ä —Å –ø–∞—Ä–∞–º–µ—Ç—Ä–∞–º–∏
{
    objNum = ++num;
    ++counter;
}

Complex::Complex(Complex &obj): real(obj.real), image(obj.image)        // –∫–æ–Ω—Å—Ç—Ä—É–∫—Ç–æ—Ä –∫–æ–ø–∏—Ä–æ–≤–∞–Ω–∏—è
{
    objNum = ++num;
    ++counter;
}

Complex::~Complex()                                                     // –¥–µ—Å—Ç—Ä—É–∫—Ç–æ—Ä
{
    --counter;
    cout<<"–î–ï–°–¢–†–£–ö–¢–û–†: id"<<objNum<<" —É–¥–∞–ª–µ–Ω."<<endl;
    Sleep(250);
}

int Complex::getCounter()                                               // –≤–æ–∑–≤—Ä–∞—Ç —Å—á—ë—Ç—á–∏–∫–∞
{
    return counter;
}

void Complex::edit()                                                    // —Ä–µ–¥–∞–∫—Ç–∏—Ä–æ–≤–∞–Ω–∏–µ –æ–±—ä–µ–∫—Ç–∞
{
    cout<<endl<<"–í–≤–µ–¥–∏—Ç–µ –¥–µ–π—Å—Ç–≤–∏—Ç–µ–ª—å–Ω—É—é —á–∞—Å—Ç—å Z: real= "<<endl;
    cin>>real;
    cout<<"–í–≤–µ–¥–∏—Ç–µ –º–Ω–∏–º—É—é —á–∞—Å—Ç—å Z: image= "<<endl;
    cin>>image;
    return;
}

void Complex::del(Complex* &obj)                            // —É–¥–∞–ª–µ–Ω–∏–µ –æ–±—ä–µ–∫—Ç–∞
{
    if (obj!=NULL)
    {
        delete obj;
        obj = NULL;
    }
    return;
}

void Complex::showObject()                                  // –≤—ã–≤–æ–¥ –æ–±—ä–µ–∫—Ç–æ–≤
{
    cout<<"Z="<<real<<"+"<<image<<"*i"<<"\t"<<"|Z|="<<mod()<<"\t";
    if (arg()!=0) 
        cout<<"arg Z="<<arg()*180/pi<<"\t"<<endl;
    else 
        cout<<"n/a"<<endl;
    return;
}

double Complex::mod()                                       // –º–æ–¥—É–ª—å
{
    return sqrt(real*real+image*image);
}

double Complex::arg()                                       // –∞—Ä–≥—É–º–µ–Ω—Ç
{
    if (real>0) return atan(image/real);
    if (real<0)
    {
        if (image>0) return pi+atan(image/real);
        if (image<0) return -pi+atan(image/real);
        if (image==0) return pi;
    }
    if (real==0)
    {
        if (image>0) return pi/2;
        if (image<0) return -pi/2;
=======
#include "comPlex.h"

comPlex::comPlex ( )                                                    // ÍÓÌÒÚÛÍÚÓ ÔÓ ÛÏÓÎ˜‡ÌË˛
{
    real = 0;
    image = 0;
    cout << counter++;
}

comPlex::~comPlex ( )
{
    system ( "cls" );
    cout << "DESTRUCTOR: " << counter-- << " Good bye!!" << endl;
}

bool comPlex::entering ( )                                              // ‚‚Ó‰ ˜ÎÂÌÓ‚ ÍÓÏÔÎÂÍÒÌÓ„Ó ˜ËÒÎ‡
{
    double tmpReal , tmpImage;                                          // ‚ÂÏÂÌÌ˚Â ÔÂÂÏÂÌÌ˚Â ‰Îˇ ÔÓ‚ÂÍË Ì‡ ÌÓÎ¸
    cout << "Enter real part of complex number Z: real= " ;             // ‰ÂÈÒÚ‚ËÚÂÎ¸Ì‡ˇ ˜‡ÒÚ¸
    cin >> tmpReal;
    cout << "Enter image part of complex number Z: image= " ;           // ÏÌËÏ‡ˇ ˜‡ÒÚ¸
    cin >> tmpImage;
    cout << endl;

    if ( tmpReal == 0 && tmpImage == 0 )
{
        cout << "Module |Z| is 0 " << endl;
        cout << "ARGUMENT IS NOT DEFINED!!!" << endl;
        _getch ( );
        return false;
    }
    real = tmpReal;
    image = tmpImage;
    return true;
}

double comPlex::mod ( )                                             // ÏÓ‰ÛÎ¸
{
    return sqrt ( real*real + image*image );
}

double comPlex::arg ( )                                             // ‡„ÛÏÂÌÚ
{
    if ( real > 0 ) return atan ( image / real );
    if ( real < 0 ) 
    {
        if ( image > 0 ) return pi + atan ( image / real );
        if ( image < 0 ) return -pi + atan ( image / real );
        if ( image == 0 ) return pi;
    }
    if ( real == 0 )
    {
        if ( image > 0 ) return pi / 2;
        if ( image < 0 ) return -pi / 2;
>>>>>>> 88b49302bccfe1ab86b747c9ffc12aff4fab0500
    }
    return 0;
}