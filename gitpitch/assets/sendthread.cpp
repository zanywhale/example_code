# Send Thread
if( tmp.at("id").get<std::string>().compare("1") == 0){
    tmp["contents"] = PGP_m->Enc(tmp.at("padding").get<std::string>(), g_km->ReturnGithubID());
}
if( connect(sockFd, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
...
    n = write(sockFd, msgStr.substr(i*bufSize,bufSize).c_str(), bufSize);
    if( n < 0 ) {
        perror("ERROR writing msg to socket\n");
        close(sockFd);
    }
}
General : id(1) && bullian(0 or 1)
Abnormal: id(1) && bullian(???)
