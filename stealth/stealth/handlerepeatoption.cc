//#include "stealth.ih"
//
//void Stealth::handleRepeatOption()
//{
//    if (    if (d_arg.option(&value, "repeat"))
//    {
//        if (!s_keepAlive)
//            fmsg << "--repeat requires --keep-alive" << endl;
//
//        istringstream in(value);
//
//        if (!(in >> s_repeatInterval))          // value 0: wait indefinite
//            fmsg << "--repeat requires <seconds> until next run" << endl;
//
//        if (s_repeatInterval < s_shortestRepeatInterval)
//        {
//            wmsg << "`--repeat " << s_repeatInterval << 
//                    "' changed to: `--repeat " << s_shortestRepeatInterval <<
//                                                              '\'' << endl;
//            s_repeatInterval = s_shortestRepeatInterval;
//        }
//        else if (s_repeatInterval > 
//                        static_cast<size_t>(numeric_limits<int>::max()))
//            s_repeatInterval = numeric_limits<int>::max();
//    }
//}
//
