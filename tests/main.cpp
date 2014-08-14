// Note: This is equivalent to QTEST_APPLESS_MAIN for multiple test classes.
#include "copy_playlist_backend_TEST.h"
int main(int argc, char** argv)
{
   int status = 0;
   {
      Testbackend tc;
      status |= QTest::qExec(&tc, argc, argv);
   }
   return status;
}