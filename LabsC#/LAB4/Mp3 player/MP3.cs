using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace WindowsFormsApp1
{
    class MP3 : IDisposable
    {
        [DllImport("winmm.dll")]
        static extern Int32 mciSendString(string command,
           StringBuilder buffer, int bufferSize, IntPtr hwndCallback);
        public MP3(string filename)
        {
            const string FORMAT = @"open ""{0}"" type mpegvideo alias MediaFile";
            string command = String.Format(FORMAT, filename);
            mciSendString(command, null, 0, IntPtr.Zero);
        }


        public void Play()
        {
            string command = "play MediaFile";
            mciSendString(command, null, 0, IntPtr.Zero);
        }

        public void Stop()
        {
            string command = "close MediaFile";
            mciSendString(command, null, 0, IntPtr.Zero);

        }


        public void SetVolume(int volume)
        {
            string command = "setaudio MediaFile volume to " + (volume * 100).ToString();
            mciSendString(command, null, 0, IntPtr.Zero);
        }

        public void Dispose()
        {
            Stop();
        }
    }
}
