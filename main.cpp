#include "Trackr.h"

int main(int argc, char** argv)
{
    openni::Status rc = openni::STATUS_OK;

    Trackr trackr("Trackr");

    rc = trackr.Init(argc, argv);
    if (rc != openni::STATUS_OK)
    {
        return 1;
    }
    trackr.Run();
}
