# Send Thread
if( tmp.at("id").get<std::string>().compare("1") == 0){
    tmp["contents"] = PGP_m->Enc(tmp.at("padding").get<std::string>(), g_km->ReturnGithubID());
}

General : id(1) && bullian(0 or 1)
Abnormal: id(1) && bullain(???)
