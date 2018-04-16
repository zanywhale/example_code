if( (tmp_id.compare("0") == 0) && tmp_bullian.compare("1") == 0) { // key alive
    r_mutex.lock();
    g_km->RecvKeyAlive(msgStr);
    r_mutex.unlock();
}
else if( (tmp_id.compare("0") == 0) && tmp_bullian.compare("0") == 0){ // key die
    r_mutex.lock();
    g_km->RecvKeyDie(msgStr);
    r_mutex.unlock();
}
else if( (tmp_id.compare("1") == 0) && (tmp2_bullian.compare("1") == 0)){
    if( tmp2_bullian.compare("1") == 0){ // my message
        //std::unique_lock<std::mutex> lck(r_mutex);
        r_mutex.lock();
        //original enqueue
        //qRecvMsg.push(tmp_content);
        string tmp2_sender = tmp2.at("githubID").get<std::string>();
        string senderGithubID = string(tmp2_sender);
        if(tmp2_sender.at(0) == '#' ) {
            senderGithubID = g_km->FindgithubID(tmp2.at("sendip").get<std::string>());
        }
        string tmp2_content = tmp2.at("content").get<std::string>();
        unordered_map<string,tuple<vector<string>*,unsigned int,time_t>*>::iterator it = chatRoomMap->find(tmp2_sender);
        //map<string,tuple<vector<string>*,unsigned int,time_t>*>::iterator itTemp = it;
        time_t now = time(NULL) + 32400;    // korean time zone
        if(it == chatRoomMap->end()) {
            vector<string>* newChatRoom = new std::vector<string>();
            // how about implementing something like g_km->AddMap();?

            // always insert to begin.
            // ACTUALLY, ALWAYS INSERT TO END, THEN ITERATE BACKWARDS.
            newChatRoom->push_back(senderGithubID + ": " + tmp2_content);
            if(tmp2_sender.at(0) == '#') {
                chatRoomMap->insert(chatRoomMap->begin(), pair<string, tuple<vector<string>*,unsigned int,time_t>*>(tmp2_sender, new tuple<vector<string>*,unsigned int,time_t>(newChatRoom, 0, now)));
            } else {
                chatRoomMap->insert(chatRoomMap->end(), pair<string, tuple<vector<string>*,unsigned int,time_t>*>(tmp2_sender, new tuple<vector<string>*,unsigned int,time_t>(newChatRoom, 0, now)));
            }
        } else {
            get<0>(*(it->second))->push_back(senderGithubID + ": " + tmp2_content);
            get<2>(*(it->second)) = now;
            pair<string, tuple<vector<string>*,unsigned int,time_t>*> newEntry(*it);
            //chatRoomMap->erase(it);
            chatRoomMap->erase(tmp2_sender);
            chatRoomMap->insert(chatRoomMap->begin(), newEntry);
        }
        r_mutex.unlock();
        //r_cv.notify_one();
    }
}
else{ // not my message
        s_mutex.lock();
        qSendMsg.push(tmp_content);
        s_mutex.unlock();
}
