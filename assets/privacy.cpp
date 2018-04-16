string command = "gpg --batch --yes --passphrase '";
command.append(this->passPhrase);
command.append("' --output ");
command.append(randomFile);
command.append(" --decrypt ");
command.append(randomFile+" 2>&1");
pipe = popen(command.c_str(),"r");
### Attacker can read in this term! ###
ifstream tmpFile2(randomFile.data());
if(tmpFile2.is_open()) {
    tmpFile2.seekg(0, std::ios::end);
    dec.reserve(tmpFile2.tellg());
    tmpFile2.seekg(0, std::ios::beg);
    dec.assign((std::istreambuf_iterator<char>(tmpFile2)),std::istreambuf_iterator<char>());
    tmpFile2.close();
}
command = "rm "+randomFile; 
### Attacker can read in this term! ###
pipe = popen(command.c_str(),"r");
