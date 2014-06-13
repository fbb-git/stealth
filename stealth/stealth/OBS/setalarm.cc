//#include "stealth.ih"
//
//void Stealth::setAlarm()
//{
//    size_t random_wait = 
//        s_delayInterval ? 
//            static_cast<size_t>(random() % s_delayInterval)
//        :
//            0;
//
//    if (Arg::instance().option('d'))
//    {
//        cerr << "Would have waited " << random_wait << " seconds\n"
//             << "Randomly selected from " << s_delayInterval << 
//            " seconds\n";
//        random_wait = 0;
//    }
//
//    s_selector.setAlarm(s_repeatInterval + random_wait);
//}
