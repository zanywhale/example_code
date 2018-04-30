# Send Thread
if( tmp.at("id").get<std::string>().compare("1") == 0){
    tmp["contents"] = PGP_m->Enc(tmp.at("padding").get<std::string>(), g_km->ReturnGithubID());
}

# Enc
change_plain = ReplaceAll(input_plain, std::string("\""), std::string("\\\""));
string command = "echo \"";
command.append(change_plain);
command.append("\" | gpg --encrypt --armor --yes --trust-mdoel always -r ");
command.append(recipientID);
command.append(" 2>&1");
pipe = popen(command.c_str(), "r");
