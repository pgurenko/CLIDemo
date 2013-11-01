using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpLib
{
    public enum CSharpClassMood
    { 
        Undefined,
        Sad,
        Happy
    }

    public class MyEventArgs : EventArgs
    {
        public string Str { get; set; }
        public CSharpClassMood Enum { get; set; }

        public MyEventArgs(string argStr, CSharpClassMood argEnum)
        {
            Str = argStr;
            Enum = argEnum;
        }
    }

    public class CSharpClass
    {
        public event EventHandler<MyEventArgs> MyEvent;

        public CSharpClass()
        {
            Console.WriteLine("Managed: CSharpClass.Constructor");
        }

        public string myMethod(int arg)
        {
            Console.WriteLine("Managed: CSharpClass.myMethod(" + arg + ")");

            return "Hello, unmanaged caller! Your arg is " + arg;
        }

        public void FireMyEvent()
        {
            Console.WriteLine("Managed: CSharpClass.FireMyEvent");

            if (MyEvent != null)
            {
                MyEvent(this, new MyEventArgs("Hello unmanaged world! Sending you this string with my mood besides.", CSharpClassMood.Happy));
            }
        }
    }
}
