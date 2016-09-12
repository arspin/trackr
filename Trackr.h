#ifndef _NITE_USER_VIEWER_H_
#define _NITE_USER_VIEWER_H_

#include "NiTE.h"

#define MAX_DEPTH 10000

class Trackr
{
public:
    Trackr(const char* strSampleName);
    virtual ~Trackr();

    virtual openni::Status Init(int argc, char **argv);
    virtual openni::Status Run();    //Does not return

protected:
    virtual void Display(nite::UserTracker* tracker, int startx, int starty, int stopx, int stopy, bool swap);
    //virtual void Display(nite::UserTracker*);
    virtual void DisplayPostDraw(){};    // Overload to draw over the screen image

    virtual void OnKey(unsigned char key, int x, int y);

    virtual openni::Status InitOpenGL(int argc, char **argv);
    void InitOpenGLHooks();

    void Finalize();

private:
    Trackr(const Trackr&);
    Trackr& operator=(Trackr&);

    static Trackr* ms_self;
    static void glutIdle();
    static void glutDisplay();
    static void glutKeyboard(unsigned char key, int x, int y);

    float                m_pDepthHist[MAX_DEPTH];
    char            m_strSampleName[ONI_MAX_STR];
    openni::RGB888Pixel*        m_pTexMap;
    unsigned int        m_nTexMapX;
    unsigned int        m_nTexMapY;

    openni::Device        m_device1;
    openni::Device        m_device2;
    nite::UserTracker* m_pUserTracker1;
    nite::UserTracker* m_pUserTracker2;

    nite::UserId m_poseUser;
    uint64_t m_poseTime;

private:
    openni::Status InitDevice(openni::Device& dev, nite::UserTracker& tr);
};


#endif // _NITE_USER_VIEWER_H_
