#include "souffle/CompiledSouffle.h"

namespace souffle {
using namespace ram;
class Sf_nfsa2fsa_auto : public SouffleProgram {
private:
static bool regex_wrapper(const char *pattern, const char *text) {
   bool result = false; 
   try { result = std::regex_match(text, std::regex(pattern)); } catch(...) { 
     std::cerr << "warning: wrong pattern provided for match(\"" << pattern << "\",\"" << text << "\")\n";
}
   return result;
}
public:
SymbolTable symTable;
// -- Table: Fsa_Word_len
ram::Relation<2,ram::index<0,1>> rel_Fsa_Word_len;
// -- Table: _temp1_Fsa_Word_len
ram::Relation<2,ram::index<0,1>> rel__temp1_Fsa_Word_len;
// -- Table: _temp2_Fsa_Word_len
ram::Relation<2,ram::index<0,1>> rel__temp2_Fsa_Word_len;
// -- Table: Fsa_Word_sublist
ram::Relation<1,ram::index<0>> rel_Fsa_Word_sublist;
// -- Table: _temp1_Fsa_Word_sublist
ram::Relation<1> rel__temp1_Fsa_Word_sublist;
// -- Table: _temp2_Fsa_Word_sublist
ram::Relation<1> rel__temp2_Fsa_Word_sublist;
// -- Table: Fsa_accepts
ram::Relation<1> rel_Fsa_accepts;
// -- Table: Fsa_accepts_from_state
ram::Relation<2,ram::index<0,1>> rel_Fsa_accepts_from_state;
// -- Table: _temp1_Fsa_accepts_from_state
ram::Relation<2,ram::index<0,1>> rel__temp1_Fsa_accepts_from;
// -- Table: _temp2_Fsa_accepts_from_state
ram::Relation<2,ram::index<0,1>> rel__temp2_Fsa_accepts_from;
// -- Table: Fsa_final
ram::Relation<1> rel_Fsa_final;
// -- Table: Fsa_max_acceptance_size
ram::Relation<1> rel_Fsa_max_acceptance_size;
// -- Table: Fsa_start_state
ram::Relation<1> rel_Fsa_start_state;
// -- Table: Fsa_tr
ram::Relation<3,ram::index<0,2>> rel_Fsa_tr;
// -- Table: FsaState_element
ram::Relation<1,ram::index<0>> rel_FsaState_element;
// -- Table: FsaState_len
ram::Relation<2,ram::index<0,1>> rel_FsaState_len;
// -- Table: _temp1_FsaState_len
ram::Relation<2,ram::index<0,1>> rel__temp1_FsaState_len;
// -- Table: _temp2_FsaState_len
ram::Relation<2,ram::index<0,1>> rel__temp2_FsaState_len;
// -- Table: FsaState_member_at
ram::Relation<3,ram::index<1,2>,ram::index<2,0,1>> rel_FsaState_member_at;
// -- Table: _temp1_FsaState_member_at
ram::Relation<3,ram::index<0,2>> rel__temp1_FsaState_member_;
// -- Table: _temp2_FsaState_member_at
ram::Relation<3,ram::index<0,2>> rel__temp2_FsaState_member_;
// -- Table: FsaState_sublist
ram::Relation<1,ram::index<0>> rel_FsaState_sublist;
// -- Table: _temp1_FsaState_sublist
ram::Relation<1> rel__temp1_FsaState_sublist;
// -- Table: _temp2_FsaState_sublist
ram::Relation<1> rel__temp2_FsaState_sublist;
// -- Table: FsaState_vector
ram::Relation<1> rel_FsaState_vector;
// -- Table: Nfsa_Word_len
ram::Relation<2,ram::index<0,1>> rel_Nfsa_Word_len;
// -- Table: _temp1_Nfsa_Word_len
ram::Relation<2,ram::index<0,1>> rel__temp1_Nfsa_Word_len;
// -- Table: _temp2_Nfsa_Word_len
ram::Relation<2,ram::index<0,1>> rel__temp2_Nfsa_Word_len;
// -- Table: Nfsa_Word_sublist
ram::Relation<1,ram::index<0>> rel_Nfsa_Word_sublist;
// -- Table: _temp1_Nfsa_Word_sublist
ram::Relation<1> rel__temp1_Nfsa_Word_sublis;
// -- Table: _temp2_Nfsa_Word_sublist
ram::Relation<1> rel__temp2_Nfsa_Word_sublis;
// -- Table: Nfsa_accepts
ram::Relation<1> rel_Nfsa_accepts;
// -- Table: Nfsa_accepts_from_state
ram::Relation<2,ram::index<0,1>> rel_Nfsa_accepts_from_state;
// -- Table: _temp1_Nfsa_accepts_from_state
ram::Relation<2,ram::index<0,1>> rel__temp1_Nfsa_accepts_fro;
// -- Table: _temp2_Nfsa_accepts_from_state
ram::Relation<2,ram::index<0,1>> rel__temp2_Nfsa_accepts_fro;
// -- Table: Nfsa_final
ram::Relation<1> rel_Nfsa_final;
// -- Table: Nfsa_max_acceptance_size
ram::Relation<1> rel_Nfsa_max_acceptance_siz;
// -- Table: Nfsa_start_state
ram::Relation<1,ram::index<0>> rel_Nfsa_start_state;
// -- Table: alphabet
ram::Relation<1> rel_alphabet;
// -- Table: fsa_accepted
ram::Relation<1> rel_fsa_accepted;
souffle::RelationWrapper<0,ram::Relation<1>,Tuple<RamDomain,1>,1,false,true> wrapper_fsa_accepted;
// -- Table: fsa_state_to_str
ram::Relation<2,ram::index<0,1>> rel_fsa_state_to_str;
// -- Table: _temp1_fsa_state_to_str
ram::Relation<2,ram::index<0>> rel__temp1_fsa_state_to_str;
// -- Table: _temp2_fsa_state_to_str
ram::Relation<2,ram::index<0>> rel__temp2_fsa_state_to_str;
// -- Table: fsa_tr
ram::Relation<3> rel_fsa_tr;
souffle::RelationWrapper<1,ram::Relation<3>,Tuple<RamDomain,3>,3,false,true> wrapper_fsa_tr;
// -- Table: has_x
ram::Relation<3,ram::index<0,1,2>> rel_has_x;
// -- Table: nfsa_accepted
ram::Relation<1> rel_nfsa_accepted;
souffle::RelationWrapper<2,ram::Relation<1>,Tuple<RamDomain,1>,1,false,true> wrapper_nfsa_accepted;
// -- Table: not_fsa_start_state
ram::Relation<1,ram::index<0>> rel_not_fsa_start_state;
// -- Table: not_fsa_tr
ram::Relation<3,ram::index<0,1,2>> rel_not_fsa_tr;
// -- Table: state
ram::Relation<1> rel_state;
// -- Table: tr
ram::Relation<3,ram::index<2>,ram::index<0,2>> rel_tr;
souffle::RelationWrapper<3,ram::Relation<3,ram::index<2>,ram::index<0,2>>,Tuple<RamDomain,3>,3,true,false> wrapper_tr;
// -- Table: word_to_str
ram::Relation<2,ram::index<0,1>> rel_word_to_str;
// -- Table: _temp1_word_to_str
ram::Relation<2,ram::index<0>> rel__temp1_word_to_str;
// -- Table: _temp2_word_to_str
ram::Relation<2,ram::index<0>> rel__temp2_word_to_str;
public:
Sf_nfsa2fsa_auto() : 
wrapper_fsa_accepted(rel_fsa_accepted,symTable,"fsa_accepted",std::array<const char *,1>{"s:String"},std::array<const char *,1>{"w"}),
wrapper_fsa_tr(rel_fsa_tr,symTable,"fsa_tr",std::array<const char *,3>{"s:String","s:String","s:Letter"},std::array<const char *,3>{"s","q","c"}),
wrapper_nfsa_accepted(rel_nfsa_accepted,symTable,"nfsa_accepted",std::array<const char *,1>{"s:String"},std::array<const char *,1>{"w"}),
wrapper_tr(rel_tr,symTable,"tr",std::array<const char *,3>{"i:N","i:N","s:Letter"},std::array<const char *,3>{"s1","s2","x"}){
addRelation("fsa_accepted",&wrapper_fsa_accepted,0,1);
addRelation("fsa_tr",&wrapper_fsa_tr,0,1);
addRelation("nfsa_accepted",&wrapper_nfsa_accepted,0,1);
addRelation("tr",&wrapper_tr,1,0);
// -- initialize symbol table --
static const char *symbols[]={
	R"( )",
	R"(0)",
	R"(1)",
};
symTable.insert(symbols,3);

}
void run() {
// -- initialize counter --
std::atomic<RamDomain> ctr(0);

#if defined(__EMBEDDED_SOUFFLE__) && defined(_OPENMP)
omp_set_num_threads(1);
#endif

// -- query evaluation --
if (!rel_tr.empty()) [&](){
auto part = rel_tr.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_state_op_ctxt,rel_state.createContext());
CREATE_OP_CONTEXT(rel_tr_op_ctxt,rel_tr.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
Tuple<RamDomain,1> tuple({env0[0]});
rel_state.insert(tuple,READ_OP_CONTEXT(rel_state_op_ctxt));
}
PARALLEL_END;
}
();if (!rel_tr.empty()) [&](){
auto part = rel_tr.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_state_op_ctxt,rel_state.createContext());
CREATE_OP_CONTEXT(rel_tr_op_ctxt,rel_tr.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
Tuple<RamDomain,1> tuple({env0[1]});
rel_state.insert(tuple,READ_OP_CONTEXT(rel_state_op_ctxt));
}
PARALLEL_END;
}
();if (!rel_tr.empty()) [&](){
auto part = rel_tr.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
CREATE_OP_CONTEXT(rel_tr_op_ctxt,rel_tr.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
Tuple<RamDomain,1> tuple({env0[2]});
rel_alphabet.insert(tuple,READ_OP_CONTEXT(rel_alphabet_op_ctxt));
}
PARALLEL_END;
}
();[&](){
CREATE_OP_CONTEXT(rel_Nfsa_final_op_ctxt,rel_Nfsa_final.createContext());
CREATE_OP_CONTEXT(rel_state_op_ctxt,rel_state.createContext());
ram::Tuple<RamDomain,1> env0;
RamDomain res = MIN_RAM_DOMAIN;
auto& range = rel_state;
if(!range.empty()) {
for(const auto& cur : range) {
env0 = cur;
res = std::max(res,env0[0]);
}
env0[0] = res;
{
Tuple<RamDomain,1> tuple({env0[0]});
rel_Nfsa_final.insert(tuple,READ_OP_CONTEXT(rel_Nfsa_final_op_ctxt));
}
}
}
();rel_Fsa_max_acceptance_size.insert(5);
rel_Fsa_Word_len.insert(0,0);
rel__temp1_Fsa_Word_len.insertAll(rel_Fsa_Word_len);
rel_Fsa_Word_sublist.insert(0);
rel__temp1_Fsa_Word_sublist.insertAll(rel_Fsa_Word_sublist);
for(;;) {
SECTIONS_START;
SECTION_START;
if (!rel_Fsa_Word_len.empty()&&!rel__temp1_Fsa_Word_sublist.empty()) [&](){
auto part = rel__temp1_Fsa_Word_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt,rel_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt,rel__temp1_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_Word_sublist_op_ctxt,rel__temp1_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt,rel__temp2_Fsa_Word_len.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel_Fsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( ((!rel_Fsa_Word_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt))) && (!rel__temp1_Fsa_Word_len.contains(Tuple<RamDomain,2>({env1[1],env2[1]}),READ_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt))))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp2_Fsa_Word_len.insert(tuple,READ_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();if (!rel_Fsa_Word_sublist.empty()&&!rel__temp1_Fsa_Word_len.empty()) [&](){
auto part = rel_Fsa_Word_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt,rel_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt,rel_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt,rel__temp1_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt,rel__temp2_Fsa_Word_len.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel__temp1_Fsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel_Fsa_Word_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp2_Fsa_Word_len.insert(tuple,READ_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTION_START;
if (!rel_Fsa_Word_len.empty()&&!rel_Fsa_max_acceptance_size.empty()&&!rel__temp1_Fsa_Word_sublist.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt,rel_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt,rel_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Fsa_max_acceptance_size_op_ctxt,rel_Fsa_max_acceptance_size.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt,rel__temp1_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_Word_sublist_op_ctxt,rel__temp1_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_Word_sublist_op_ctxt,rel__temp2_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel__temp1_Fsa_Word_sublist) {
if( !rel_Fsa_Word_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel_Fsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel__temp1_Fsa_Word_len.contains(Tuple<RamDomain,2>({env1[0],env2[1]}),READ_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt))) {
for(const auto& env3 : rel_Fsa_max_acceptance_size) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp2_Fsa_Word_sublist.insert(tuple,READ_OP_CONTEXT(rel__temp2_Fsa_Word_sublist_op_ctxt));
}
}
}
}
}
}
}
PARALLEL_END;
}
();if (!rel_Fsa_Word_sublist.empty()&&!rel_Fsa_max_acceptance_size.empty()&&!rel__temp1_Fsa_Word_len.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt,rel_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Fsa_max_acceptance_size_op_ctxt,rel_Fsa_max_acceptance_size.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt,rel__temp1_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_Word_sublist_op_ctxt,rel__temp2_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_Fsa_Word_sublist) {
if( !rel_Fsa_Word_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel__temp1_Fsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
for(const auto& env3 : rel_Fsa_max_acceptance_size) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp2_Fsa_Word_sublist.insert(tuple,READ_OP_CONTEXT(rel__temp2_Fsa_Word_sublist_op_ctxt));
}
}
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTIONS_END;
if(((rel__temp2_Fsa_Word_len.empty()) && (rel__temp2_Fsa_Word_sublist.empty()))) break;
SECTIONS_START;
SECTION_START;
rel_Fsa_Word_len.insertAll(rel__temp2_Fsa_Word_len);
rel__temp1_Fsa_Word_len.purge();
SECTION_END
SECTION_START;
rel_Fsa_Word_sublist.insertAll(rel__temp2_Fsa_Word_sublist);
rel__temp1_Fsa_Word_sublist.purge();
SECTION_END
SECTIONS_END;
SECTIONS_START;
SECTION_START;
if (!rel_Fsa_Word_len.empty()&&!rel__temp2_Fsa_Word_sublist.empty()) [&](){
auto part = rel__temp2_Fsa_Word_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt,rel_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt,rel__temp1_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt,rel__temp2_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_Word_sublist_op_ctxt,rel__temp2_Fsa_Word_sublist.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel_Fsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( ((!rel_Fsa_Word_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt))) && (!rel__temp2_Fsa_Word_len.contains(Tuple<RamDomain,2>({env1[1],env2[1]}),READ_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt))))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp1_Fsa_Word_len.insert(tuple,READ_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();if (!rel_Fsa_Word_sublist.empty()&&!rel__temp2_Fsa_Word_len.empty()) [&](){
auto part = rel_Fsa_Word_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt,rel_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt,rel_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt,rel__temp1_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt,rel__temp2_Fsa_Word_len.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel__temp2_Fsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel_Fsa_Word_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp1_Fsa_Word_len.insert(tuple,READ_OP_CONTEXT(rel__temp1_Fsa_Word_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTION_START;
if (!rel_Fsa_Word_len.empty()&&!rel_Fsa_max_acceptance_size.empty()&&!rel__temp2_Fsa_Word_sublist.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt,rel_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt,rel_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Fsa_max_acceptance_size_op_ctxt,rel_Fsa_max_acceptance_size.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_Word_sublist_op_ctxt,rel__temp1_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt,rel__temp2_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_Word_sublist_op_ctxt,rel__temp2_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel__temp2_Fsa_Word_sublist) {
if( !rel_Fsa_Word_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel_Fsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel_Fsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel__temp2_Fsa_Word_len.contains(Tuple<RamDomain,2>({env1[0],env2[1]}),READ_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt))) {
for(const auto& env3 : rel_Fsa_max_acceptance_size) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp1_Fsa_Word_sublist.insert(tuple,READ_OP_CONTEXT(rel__temp1_Fsa_Word_sublist_op_ctxt));
}
}
}
}
}
}
}
PARALLEL_END;
}
();if (!rel_Fsa_Word_sublist.empty()&&!rel_Fsa_max_acceptance_size.empty()&&!rel__temp2_Fsa_Word_len.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt,rel_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Fsa_max_acceptance_size_op_ctxt,rel_Fsa_max_acceptance_size.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_Word_sublist_op_ctxt,rel__temp1_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt,rel__temp2_Fsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_Fsa_Word_sublist) {
if( !rel_Fsa_Word_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel__temp2_Fsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp2_Fsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
for(const auto& env3 : rel_Fsa_max_acceptance_size) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp1_Fsa_Word_sublist.insert(tuple,READ_OP_CONTEXT(rel__temp1_Fsa_Word_sublist_op_ctxt));
}
}
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTIONS_END;
if(((rel__temp1_Fsa_Word_len.empty()) && (rel__temp1_Fsa_Word_sublist.empty()))) break;
SECTIONS_START;
SECTION_START;
rel_Fsa_Word_len.insertAll(rel__temp1_Fsa_Word_len);
rel__temp2_Fsa_Word_len.purge();
SECTION_END
SECTION_START;
rel_Fsa_Word_sublist.insertAll(rel__temp1_Fsa_Word_sublist);
rel__temp2_Fsa_Word_sublist.purge();
SECTION_END
SECTIONS_END;
}
rel__temp1_Fsa_Word_len.purge();
rel__temp2_Fsa_Word_len.purge();
rel__temp1_Fsa_Word_sublist.purge();
rel__temp2_Fsa_Word_sublist.purge();
rel_Fsa_Word_len.purge();
rel_Fsa_max_acceptance_size.purge();
rel_word_to_str.insert(0,0);
rel__temp1_word_to_str.insertAll(rel_word_to_str);
for(;;) {
if (!rel_Fsa_Word_sublist.empty()&&!rel__temp1_word_to_str.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt,rel_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_word_to_str_op_ctxt,rel__temp1_word_to_str.createContext());
CREATE_OP_CONTEXT(rel__temp2_word_to_str_op_ctxt,rel__temp2_word_to_str.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
CREATE_OP_CONTEXT(rel_word_to_str_op_ctxt,rel_word_to_str.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_Fsa_Word_sublist) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel__temp1_word_to_str.equalRange<0>(key,READ_OP_CONTEXT(rel__temp1_word_to_str_op_ctxt));
for(const auto& env2 : range) {
if( !rel_word_to_str.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)env0[0])) + std::string(symTable.resolve((size_t)env2[1]))).c_str())}),READ_OP_CONTEXT(rel_word_to_str_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)env0[0])) + std::string(symTable.resolve((size_t)env2[1]))).c_str())});
rel__temp2_word_to_str.insert(tuple,READ_OP_CONTEXT(rel__temp2_word_to_str_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();if(rel__temp2_word_to_str.empty()) break;
rel_word_to_str.insertAll(rel__temp2_word_to_str);
rel__temp1_word_to_str.purge();
if (!rel_Fsa_Word_sublist.empty()&&!rel__temp2_word_to_str.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt,rel_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_word_to_str_op_ctxt,rel__temp1_word_to_str.createContext());
CREATE_OP_CONTEXT(rel__temp2_word_to_str_op_ctxt,rel__temp2_word_to_str.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
CREATE_OP_CONTEXT(rel_word_to_str_op_ctxt,rel_word_to_str.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_Fsa_Word_sublist) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel__temp2_word_to_str.equalRange<0>(key,READ_OP_CONTEXT(rel__temp2_word_to_str_op_ctxt));
for(const auto& env2 : range) {
if( !rel_word_to_str.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)env0[0])) + std::string(symTable.resolve((size_t)env2[1]))).c_str())}),READ_OP_CONTEXT(rel_word_to_str_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)env0[0])) + std::string(symTable.resolve((size_t)env2[1]))).c_str())});
rel__temp1_word_to_str.insert(tuple,READ_OP_CONTEXT(rel__temp1_word_to_str_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();if(rel__temp1_word_to_str.empty()) break;
rel_word_to_str.insertAll(rel__temp1_word_to_str);
rel__temp2_word_to_str.purge();
}
rel__temp1_word_to_str.purge();
rel__temp2_word_to_str.purge();
rel_Nfsa_start_state.insert(1);
rel_FsaState_element.insert(0);
rel_FsaState_element.insert(1);
rel_FsaState_len.insert(0,0);
rel__temp1_FsaState_len.insertAll(rel_FsaState_len);
rel_FsaState_sublist.insert(0);
rel__temp1_FsaState_sublist.insertAll(rel_FsaState_sublist);
for(;;) {
SECTIONS_START;
SECTION_START;
if (!rel_FsaState_len.empty()&&!rel__temp1_FsaState_sublist.empty()) [&](){
auto part = rel__temp1_FsaState_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_len_op_ctxt,rel_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt,rel__temp1_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_sublist_op_ctxt,rel__temp1_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt,rel__temp2_FsaState_len.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel_FsaState_len.equalRange<0>(key,READ_OP_CONTEXT(rel_FsaState_len_op_ctxt));
for(const auto& env2 : range) {
if( ((!rel_FsaState_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_FsaState_len_op_ctxt))) && (!rel__temp1_FsaState_len.contains(Tuple<RamDomain,2>({env1[1],env2[1]}),READ_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt))))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp2_FsaState_len.insert(tuple,READ_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();if (!rel_FsaState_sublist.empty()&&!rel__temp1_FsaState_len.empty()) [&](){
auto part = rel_FsaState_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_len_op_ctxt,rel_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt,rel__temp1_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt,rel__temp2_FsaState_len.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel__temp1_FsaState_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel_FsaState_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_FsaState_len_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp2_FsaState_len.insert(tuple,READ_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTION_START;
if (!rel_FsaState_element.empty()&&!rel_FsaState_len.empty()&&!rel_Nfsa_final.empty()&&!rel__temp1_FsaState_sublist.empty()) [&](){
auto part = rel_FsaState_element.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_element_op_ctxt,rel_FsaState_element.createContext());
CREATE_OP_CONTEXT(rel_FsaState_len_op_ctxt,rel_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_final_op_ctxt,rel_Nfsa_final.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt,rel__temp1_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_sublist_op_ctxt,rel__temp1_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_sublist_op_ctxt,rel__temp2_FsaState_sublist.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel__temp1_FsaState_sublist) {
if( !rel_FsaState_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_FsaState_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel_FsaState_len.equalRange<0>(key,READ_OP_CONTEXT(rel_FsaState_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel__temp1_FsaState_len.contains(Tuple<RamDomain,2>({env1[0],env2[1]}),READ_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt))) {
for(const auto& env3 : rel_Nfsa_final) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp2_FsaState_sublist.insert(tuple,READ_OP_CONTEXT(rel__temp2_FsaState_sublist_op_ctxt));
}
}
}
}
}
}
}
PARALLEL_END;
}
();if (!rel_FsaState_element.empty()&&!rel_FsaState_sublist.empty()&&!rel_Nfsa_final.empty()&&!rel__temp1_FsaState_len.empty()) [&](){
auto part = rel_FsaState_element.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_element_op_ctxt,rel_FsaState_element.createContext());
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_final_op_ctxt,rel_Nfsa_final.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt,rel__temp1_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_sublist_op_ctxt,rel__temp2_FsaState_sublist.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_FsaState_sublist) {
if( !rel_FsaState_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_FsaState_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel__temp1_FsaState_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt));
for(const auto& env2 : range) {
for(const auto& env3 : rel_Nfsa_final) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp2_FsaState_sublist.insert(tuple,READ_OP_CONTEXT(rel__temp2_FsaState_sublist_op_ctxt));
}
}
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTIONS_END;
if(((rel__temp2_FsaState_len.empty()) && (rel__temp2_FsaState_sublist.empty()))) break;
SECTIONS_START;
SECTION_START;
rel_FsaState_len.insertAll(rel__temp2_FsaState_len);
rel__temp1_FsaState_len.purge();
SECTION_END
SECTION_START;
rel_FsaState_sublist.insertAll(rel__temp2_FsaState_sublist);
rel__temp1_FsaState_sublist.purge();
SECTION_END
SECTIONS_END;
SECTIONS_START;
SECTION_START;
if (!rel_FsaState_len.empty()&&!rel__temp2_FsaState_sublist.empty()) [&](){
auto part = rel__temp2_FsaState_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_len_op_ctxt,rel_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt,rel__temp1_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt,rel__temp2_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_sublist_op_ctxt,rel__temp2_FsaState_sublist.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel_FsaState_len.equalRange<0>(key,READ_OP_CONTEXT(rel_FsaState_len_op_ctxt));
for(const auto& env2 : range) {
if( ((!rel_FsaState_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_FsaState_len_op_ctxt))) && (!rel__temp2_FsaState_len.contains(Tuple<RamDomain,2>({env1[1],env2[1]}),READ_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt))))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp1_FsaState_len.insert(tuple,READ_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();if (!rel_FsaState_sublist.empty()&&!rel__temp2_FsaState_len.empty()) [&](){
auto part = rel_FsaState_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_len_op_ctxt,rel_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt,rel__temp1_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt,rel__temp2_FsaState_len.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel__temp2_FsaState_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel_FsaState_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_FsaState_len_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp1_FsaState_len.insert(tuple,READ_OP_CONTEXT(rel__temp1_FsaState_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTION_START;
if (!rel_FsaState_element.empty()&&!rel_FsaState_len.empty()&&!rel_Nfsa_final.empty()&&!rel__temp2_FsaState_sublist.empty()) [&](){
auto part = rel_FsaState_element.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_element_op_ctxt,rel_FsaState_element.createContext());
CREATE_OP_CONTEXT(rel_FsaState_len_op_ctxt,rel_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_final_op_ctxt,rel_Nfsa_final.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_sublist_op_ctxt,rel__temp1_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt,rel__temp2_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_sublist_op_ctxt,rel__temp2_FsaState_sublist.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel__temp2_FsaState_sublist) {
if( !rel_FsaState_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_FsaState_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel_FsaState_len.equalRange<0>(key,READ_OP_CONTEXT(rel_FsaState_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel__temp2_FsaState_len.contains(Tuple<RamDomain,2>({env1[0],env2[1]}),READ_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt))) {
for(const auto& env3 : rel_Nfsa_final) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp1_FsaState_sublist.insert(tuple,READ_OP_CONTEXT(rel__temp1_FsaState_sublist_op_ctxt));
}
}
}
}
}
}
}
PARALLEL_END;
}
();if (!rel_FsaState_element.empty()&&!rel_FsaState_sublist.empty()&&!rel_Nfsa_final.empty()&&!rel__temp2_FsaState_len.empty()) [&](){
auto part = rel_FsaState_element.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_element_op_ctxt,rel_FsaState_element.createContext());
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_final_op_ctxt,rel_Nfsa_final.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_sublist_op_ctxt,rel__temp1_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt,rel__temp2_FsaState_len.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_FsaState_sublist) {
if( !rel_FsaState_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_FsaState_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel__temp2_FsaState_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp2_FsaState_len_op_ctxt));
for(const auto& env2 : range) {
for(const auto& env3 : rel_Nfsa_final) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp1_FsaState_sublist.insert(tuple,READ_OP_CONTEXT(rel__temp1_FsaState_sublist_op_ctxt));
}
}
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTIONS_END;
if(((rel__temp1_FsaState_len.empty()) && (rel__temp1_FsaState_sublist.empty()))) break;
SECTIONS_START;
SECTION_START;
rel_FsaState_len.insertAll(rel__temp1_FsaState_len);
rel__temp2_FsaState_len.purge();
SECTION_END
SECTION_START;
rel_FsaState_sublist.insertAll(rel__temp1_FsaState_sublist);
rel__temp2_FsaState_sublist.purge();
SECTION_END
SECTIONS_END;
}
rel__temp1_FsaState_len.purge();
rel__temp2_FsaState_len.purge();
rel__temp1_FsaState_sublist.purge();
rel__temp2_FsaState_sublist.purge();
if (!rel_FsaState_len.empty()&&!rel_FsaState_sublist.empty()&&!rel_Nfsa_final.empty()) [&](){
auto part = rel_FsaState_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_len_op_ctxt,rel_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel_FsaState_vector_op_ctxt,rel_FsaState_vector.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_final_op_ctxt,rel_Nfsa_final.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_Nfsa_final) {
const Tuple<RamDomain,2> key({env0[0],env1[0]});
auto range = rel_FsaState_len.equalRange<0,1>(key,READ_OP_CONTEXT(rel_FsaState_len_op_ctxt));
if(!range.empty()) {
Tuple<RamDomain,1> tuple({env0[0]});
rel_FsaState_vector.insert(tuple,READ_OP_CONTEXT(rel_FsaState_vector_op_ctxt));
}
}
}
PARALLEL_END;
}
();rel_fsa_state_to_str.insert(0,0);
rel__temp1_fsa_state_to_str.insertAll(rel_fsa_state_to_str);
for(;;) {
if (!rel_FsaState_sublist.empty()&&!rel__temp1_fsa_state_to_str.empty()) [&](){
auto part = rel_FsaState_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_fsa_state_to_str_op_ctxt,rel__temp1_fsa_state_to_str.createContext());
CREATE_OP_CONTEXT(rel__temp2_fsa_state_to_str_op_ctxt,rel__temp2_fsa_state_to_str.createContext());
CREATE_OP_CONTEXT(rel_fsa_state_to_str_op_ctxt,rel_fsa_state_to_str.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({env0[0],0});
auto range = rel__temp1_fsa_state_to_str.equalRange<0>(key,READ_OP_CONTEXT(rel__temp1_fsa_state_to_str_op_ctxt));
for(const auto& env1 : range) {
if( !rel_fsa_state_to_str.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({0,env0[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)1)) + std::string(symTable.resolve((size_t)env1[1]))).c_str())}),READ_OP_CONTEXT(rel_fsa_state_to_str_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({0,env0[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)1)) + std::string(symTable.resolve((size_t)env1[1]))).c_str())});
rel__temp2_fsa_state_to_str.insert(tuple,READ_OP_CONTEXT(rel__temp2_fsa_state_to_str_op_ctxt));
}
}
}
PARALLEL_END;
}
();if (!rel_FsaState_sublist.empty()&&!rel__temp1_fsa_state_to_str.empty()) [&](){
auto part = rel_FsaState_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_fsa_state_to_str_op_ctxt,rel__temp1_fsa_state_to_str.createContext());
CREATE_OP_CONTEXT(rel__temp2_fsa_state_to_str_op_ctxt,rel__temp2_fsa_state_to_str.createContext());
CREATE_OP_CONTEXT(rel_fsa_state_to_str_op_ctxt,rel_fsa_state_to_str.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({env0[0],0});
auto range = rel__temp1_fsa_state_to_str.equalRange<0>(key,READ_OP_CONTEXT(rel__temp1_fsa_state_to_str_op_ctxt));
for(const auto& env1 : range) {
if( !rel_fsa_state_to_str.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({1,env0[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)2)) + std::string(symTable.resolve((size_t)env1[1]))).c_str())}),READ_OP_CONTEXT(rel_fsa_state_to_str_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({1,env0[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)2)) + std::string(symTable.resolve((size_t)env1[1]))).c_str())});
rel__temp2_fsa_state_to_str.insert(tuple,READ_OP_CONTEXT(rel__temp2_fsa_state_to_str_op_ctxt));
}
}
}
PARALLEL_END;
}
();if(rel__temp2_fsa_state_to_str.empty()) break;
rel_fsa_state_to_str.insertAll(rel__temp2_fsa_state_to_str);
rel__temp1_fsa_state_to_str.purge();
if (!rel_FsaState_sublist.empty()&&!rel__temp2_fsa_state_to_str.empty()) [&](){
auto part = rel_FsaState_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_fsa_state_to_str_op_ctxt,rel__temp1_fsa_state_to_str.createContext());
CREATE_OP_CONTEXT(rel__temp2_fsa_state_to_str_op_ctxt,rel__temp2_fsa_state_to_str.createContext());
CREATE_OP_CONTEXT(rel_fsa_state_to_str_op_ctxt,rel_fsa_state_to_str.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({env0[0],0});
auto range = rel__temp2_fsa_state_to_str.equalRange<0>(key,READ_OP_CONTEXT(rel__temp2_fsa_state_to_str_op_ctxt));
for(const auto& env1 : range) {
if( !rel_fsa_state_to_str.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({0,env0[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)1)) + std::string(symTable.resolve((size_t)env1[1]))).c_str())}),READ_OP_CONTEXT(rel_fsa_state_to_str_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({0,env0[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)1)) + std::string(symTable.resolve((size_t)env1[1]))).c_str())});
rel__temp1_fsa_state_to_str.insert(tuple,READ_OP_CONTEXT(rel__temp1_fsa_state_to_str_op_ctxt));
}
}
}
PARALLEL_END;
}
();if (!rel_FsaState_sublist.empty()&&!rel__temp2_fsa_state_to_str.empty()) [&](){
auto part = rel_FsaState_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_fsa_state_to_str_op_ctxt,rel__temp1_fsa_state_to_str.createContext());
CREATE_OP_CONTEXT(rel__temp2_fsa_state_to_str_op_ctxt,rel__temp2_fsa_state_to_str.createContext());
CREATE_OP_CONTEXT(rel_fsa_state_to_str_op_ctxt,rel_fsa_state_to_str.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({env0[0],0});
auto range = rel__temp2_fsa_state_to_str.equalRange<0>(key,READ_OP_CONTEXT(rel__temp2_fsa_state_to_str_op_ctxt));
for(const auto& env1 : range) {
if( !rel_fsa_state_to_str.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({1,env0[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)2)) + std::string(symTable.resolve((size_t)env1[1]))).c_str())}),READ_OP_CONTEXT(rel_fsa_state_to_str_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({1,env0[0]})),(RamDomain)symTable.lookup((std::string(symTable.resolve((size_t)2)) + std::string(symTable.resolve((size_t)env1[1]))).c_str())});
rel__temp1_fsa_state_to_str.insert(tuple,READ_OP_CONTEXT(rel__temp1_fsa_state_to_str_op_ctxt));
}
}
}
PARALLEL_END;
}
();if(rel__temp1_fsa_state_to_str.empty()) break;
rel_fsa_state_to_str.insertAll(rel__temp1_fsa_state_to_str);
rel__temp2_fsa_state_to_str.purge();
}
rel__temp1_fsa_state_to_str.purge();
rel__temp2_fsa_state_to_str.purge();
if (!rel_FsaState_element.empty()&&!rel_FsaState_len.empty()&&!rel_FsaState_sublist.empty()&&!rel_Nfsa_final.empty()) [&](){
auto part = rel_FsaState_element.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_element_op_ctxt,rel_FsaState_element.createContext());
CREATE_OP_CONTEXT(rel_FsaState_len_op_ctxt,rel_FsaState_len.createContext());
CREATE_OP_CONTEXT(rel_FsaState_member_at_op_ctxt,rel_FsaState_member_at.createContext());
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_final_op_ctxt,rel_Nfsa_final.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_FsaState_sublist) {
const Tuple<RamDomain,1> key({env0[0]});
auto range = rel_FsaState_element.equalRange<0>(key,READ_OP_CONTEXT(rel_FsaState_element_op_ctxt));
if(!range.empty()) {
for(const auto& env3 : rel_Nfsa_final) {
for(const auto& env4 : rel_FsaState_len) {
if( ((env4[1]) <= (env3[0]))) {
auto ref = env4[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env5 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
if( ((((env0[0]) == (env5[0]))) && (((env1[0]) == (env5[1]))))) {
Tuple<RamDomain,3> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]})),env4[1],env0[0]});
rel_FsaState_member_at.insert(tuple,READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt));
}
}
}
}
}
}
}
}
PARALLEL_END;
}
();rel__temp1_FsaState_member_.insertAll(rel_FsaState_member_at);
for(;;) {
if (!rel_FsaState_element.empty()&&!rel_FsaState_sublist.empty()&&!rel__temp1_FsaState_member_.empty()) [&](){
auto part = rel_FsaState_element.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_element_op_ctxt,rel_FsaState_element.createContext());
CREATE_OP_CONTEXT(rel_FsaState_member_at_op_ctxt,rel_FsaState_member_at.createContext());
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_member__op_ctxt,rel__temp1_FsaState_member_.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_member__op_ctxt,rel__temp2_FsaState_member_.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_FsaState_sublist) {
for(const auto& env2 : rel_FsaState_element) {
const Tuple<RamDomain,3> key({env1[0],0,env2[0]});
auto range = rel__temp1_FsaState_member_.equalRange<0,2>(key,READ_OP_CONTEXT(rel__temp1_FsaState_member__op_ctxt));
for(const auto& env3 : range) {
if( !rel_FsaState_member_at.contains(Tuple<RamDomain,3>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]})),env3[1],env2[0]}),READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt))) {
Tuple<RamDomain,3> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]})),env3[1],env2[0]});
rel__temp2_FsaState_member_.insert(tuple,READ_OP_CONTEXT(rel__temp2_FsaState_member__op_ctxt));
}
}
}
}
}
PARALLEL_END;
}
();if(rel__temp2_FsaState_member_.empty()) break;
rel_FsaState_member_at.insertAll(rel__temp2_FsaState_member_);
rel__temp1_FsaState_member_.purge();
if (!rel_FsaState_element.empty()&&!rel_FsaState_sublist.empty()&&!rel__temp2_FsaState_member_.empty()) [&](){
auto part = rel_FsaState_element.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_element_op_ctxt,rel_FsaState_element.createContext());
CREATE_OP_CONTEXT(rel_FsaState_member_at_op_ctxt,rel_FsaState_member_at.createContext());
CREATE_OP_CONTEXT(rel_FsaState_sublist_op_ctxt,rel_FsaState_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_FsaState_member__op_ctxt,rel__temp1_FsaState_member_.createContext());
CREATE_OP_CONTEXT(rel__temp2_FsaState_member__op_ctxt,rel__temp2_FsaState_member_.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_FsaState_sublist) {
for(const auto& env2 : rel_FsaState_element) {
const Tuple<RamDomain,3> key({env1[0],0,env2[0]});
auto range = rel__temp2_FsaState_member_.equalRange<0,2>(key,READ_OP_CONTEXT(rel__temp2_FsaState_member__op_ctxt));
for(const auto& env3 : range) {
if( !rel_FsaState_member_at.contains(Tuple<RamDomain,3>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]})),env3[1],env2[0]}),READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt))) {
Tuple<RamDomain,3> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]})),env3[1],env2[0]});
rel__temp1_FsaState_member_.insert(tuple,READ_OP_CONTEXT(rel__temp1_FsaState_member__op_ctxt));
}
}
}
}
}
PARALLEL_END;
}
();if(rel__temp1_FsaState_member_.empty()) break;
rel_FsaState_member_at.insertAll(rel__temp1_FsaState_member_);
rel__temp2_FsaState_member_.purge();
}
rel__temp1_FsaState_member_.purge();
rel__temp2_FsaState_member_.purge();
rel_FsaState_element.purge();
rel_FsaState_len.purge();
rel_FsaState_sublist.purge();
if (!rel_FsaState_member_at.empty()) [&](){
CREATE_OP_CONTEXT(rel_FsaState_member_at_op_ctxt,rel_FsaState_member_at.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_start_state_op_ctxt,rel_Nfsa_start_state.createContext());
CREATE_OP_CONTEXT(rel_not_fsa_start_state_op_ctxt,rel_not_fsa_start_state.createContext());
const Tuple<RamDomain,3> key({0,0,1});
auto range = rel_FsaState_member_at.equalRange<2>(key,READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt));
for(const auto& env0 : range) {
if( !rel_Nfsa_start_state.contains(Tuple<RamDomain,1>({env0[1]}),READ_OP_CONTEXT(rel_Nfsa_start_state_op_ctxt))) {
Tuple<RamDomain,1> tuple({env0[0]});
rel_not_fsa_start_state.insert(tuple,READ_OP_CONTEXT(rel_not_fsa_start_state_op_ctxt));
}
}
}
();if (!rel_FsaState_member_at.empty()&&!rel_Nfsa_final.empty()) [&](){
auto part = rel_Nfsa_final.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_member_at_op_ctxt,rel_FsaState_member_at.createContext());
CREATE_OP_CONTEXT(rel_Fsa_final_op_ctxt,rel_Fsa_final.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_final_op_ctxt,rel_Nfsa_final.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
const Tuple<RamDomain,3> key({0,env0[0],1});
auto range = rel_FsaState_member_at.equalRange<1,2>(key,READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,1> tuple({env1[0]});
rel_Fsa_final.insert(tuple,READ_OP_CONTEXT(rel_Fsa_final_op_ctxt));
}
}
PARALLEL_END;
}
();if (!rel_FsaState_member_at.empty()&&!rel_tr.empty()) [&](){
CREATE_OP_CONTEXT(rel_FsaState_member_at_op_ctxt,rel_FsaState_member_at.createContext());
CREATE_OP_CONTEXT(rel_has_x_op_ctxt,rel_has_x.createContext());
CREATE_OP_CONTEXT(rel_tr_op_ctxt,rel_tr.createContext());
const Tuple<RamDomain,3> key({0,0,1});
auto range = rel_FsaState_member_at.equalRange<2>(key,READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt));
for(const auto& env0 : range) {
const Tuple<RamDomain,3> key({env0[1],0,0});
auto range = rel_tr.equalRange<0>(key,READ_OP_CONTEXT(rel_tr_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,3> tuple({env0[0],env1[1],env1[2]});
rel_has_x.insert(tuple,READ_OP_CONTEXT(rel_has_x_op_ctxt));
}
}
}
();if (!rel_FsaState_member_at.empty()&&!rel_Nfsa_start_state.empty()) [&](){
CREATE_OP_CONTEXT(rel_FsaState_member_at_op_ctxt,rel_FsaState_member_at.createContext());
CREATE_OP_CONTEXT(rel_Fsa_start_state_op_ctxt,rel_Fsa_start_state.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_start_state_op_ctxt,rel_Nfsa_start_state.createContext());
CREATE_OP_CONTEXT(rel_not_fsa_start_state_op_ctxt,rel_not_fsa_start_state.createContext());
const Tuple<RamDomain,3> key({0,0,1});
auto range = rel_FsaState_member_at.equalRange<2>(key,READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt));
for(const auto& env0 : range) {
if( !rel_not_fsa_start_state.contains(Tuple<RamDomain,1>({env0[0]}),READ_OP_CONTEXT(rel_not_fsa_start_state_op_ctxt))) {
const Tuple<RamDomain,1> key({env0[1]});
auto range = rel_Nfsa_start_state.equalRange<0>(key,READ_OP_CONTEXT(rel_Nfsa_start_state_op_ctxt));
if(!range.empty()) {
Tuple<RamDomain,1> tuple({env0[0]});
rel_Fsa_start_state.insert(tuple,READ_OP_CONTEXT(rel_Fsa_start_state_op_ctxt));
}
}
}
}
();rel_not_fsa_start_state.purge();
if (!rel_FsaState_member_at.empty()&&!rel_FsaState_vector.empty()&&!rel_alphabet.empty()&&!rel_tr.empty()) [&](){
auto part = rel_FsaState_vector.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_member_at_op_ctxt,rel_FsaState_member_at.createContext());
CREATE_OP_CONTEXT(rel_FsaState_vector_op_ctxt,rel_FsaState_vector.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
CREATE_OP_CONTEXT(rel_not_fsa_tr_op_ctxt,rel_not_fsa_tr.createContext());
CREATE_OP_CONTEXT(rel_tr_op_ctxt,rel_tr.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_FsaState_vector) {
for(const auto& env2 : rel_alphabet) {
const Tuple<RamDomain,3> key({0,0,env2[0]});
auto range = rel_tr.equalRange<2>(key,READ_OP_CONTEXT(rel_tr_op_ctxt));
for(const auto& env3 : range) {
if( !rel_FsaState_member_at.contains(Tuple<RamDomain,3>({env1[0],env3[1],1}),READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt))) {
const Tuple<RamDomain,3> key({env0[0],env3[0],1});
auto range = rel_FsaState_member_at.equalRange<0,1,2>(key,READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt));
if(!range.empty()) {
Tuple<RamDomain,3> tuple({env0[0],env1[0],env2[0]});
rel_not_fsa_tr.insert(tuple,READ_OP_CONTEXT(rel_not_fsa_tr_op_ctxt));
}
}
}
}
}
}
PARALLEL_END;
}
();if (!rel_FsaState_member_at.empty()&&!rel_FsaState_vector.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_FsaState_vector.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_member_at_op_ctxt,rel_FsaState_member_at.createContext());
CREATE_OP_CONTEXT(rel_FsaState_vector_op_ctxt,rel_FsaState_vector.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
CREATE_OP_CONTEXT(rel_has_x_op_ctxt,rel_has_x.createContext());
CREATE_OP_CONTEXT(rel_not_fsa_tr_op_ctxt,rel_not_fsa_tr.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_FsaState_vector) {
for(const auto& env2 : rel_alphabet) {
const Tuple<RamDomain,3> key({env1[0],0,1});
auto range = rel_FsaState_member_at.equalRange<0,2>(key,READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt));
for(const auto& env3 : range) {
if( !rel_has_x.contains(Tuple<RamDomain,3>({env0[0],env3[1],env2[0]}),READ_OP_CONTEXT(rel_has_x_op_ctxt))) {
Tuple<RamDomain,3> tuple({env0[0],env1[0],env2[0]});
rel_not_fsa_tr.insert(tuple,READ_OP_CONTEXT(rel_not_fsa_tr_op_ctxt));
}
}
}
}
}
PARALLEL_END;
}
();rel_has_x.purge();
if (!rel_FsaState_member_at.empty()&&!rel_FsaState_vector.empty()&&!rel_alphabet.empty()&&!rel_tr.empty()) [&](){
auto part = rel_FsaState_vector.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_member_at_op_ctxt,rel_FsaState_member_at.createContext());
CREATE_OP_CONTEXT(rel_FsaState_vector_op_ctxt,rel_FsaState_vector.createContext());
CREATE_OP_CONTEXT(rel_Fsa_tr_op_ctxt,rel_Fsa_tr.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
CREATE_OP_CONTEXT(rel_not_fsa_tr_op_ctxt,rel_not_fsa_tr.createContext());
CREATE_OP_CONTEXT(rel_tr_op_ctxt,rel_tr.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_FsaState_vector) {
for(const auto& env2 : rel_alphabet) {
if( !rel_not_fsa_tr.contains(Tuple<RamDomain,3>({env0[0],env1[0],env2[0]}),READ_OP_CONTEXT(rel_not_fsa_tr_op_ctxt))) {
const Tuple<RamDomain,3> key({0,0,env2[0]});
auto range = rel_tr.equalRange<2>(key,READ_OP_CONTEXT(rel_tr_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,3> key({env0[0],env3[0],1});
auto range = rel_FsaState_member_at.equalRange<0,1,2>(key,READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt));
if(!range.empty()) {
const Tuple<RamDomain,3> key({env1[0],env3[1],1});
auto range = rel_FsaState_member_at.equalRange<0,1,2>(key,READ_OP_CONTEXT(rel_FsaState_member_at_op_ctxt));
if(!range.empty()) {
Tuple<RamDomain,3> tuple({env0[0],env1[0],env2[0]});
rel_Fsa_tr.insert(tuple,READ_OP_CONTEXT(rel_Fsa_tr_op_ctxt));
}
}
}
}
}
}
}
PARALLEL_END;
}
();rel_not_fsa_tr.purge();
rel_FsaState_member_at.purge();
if (!rel_Fsa_final.empty()) [&](){
auto part = rel_Fsa_final.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_accepts_from_state_op_ctxt,rel_Fsa_accepts_from_state.createContext());
CREATE_OP_CONTEXT(rel_Fsa_final_op_ctxt,rel_Fsa_final.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({0,env0[0]});
rel_Fsa_accepts_from_state.insert(tuple,READ_OP_CONTEXT(rel_Fsa_accepts_from_state_op_ctxt));
}
PARALLEL_END;
}
();rel__temp1_Fsa_accepts_from.insertAll(rel_Fsa_accepts_from_state);
for(;;) {
if (!rel_FsaState_vector.empty()&&!rel_Fsa_Word_sublist.empty()&&!rel_Fsa_tr.empty()&&!rel__temp1_Fsa_accepts_from.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_vector_op_ctxt,rel_FsaState_vector.createContext());
CREATE_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt,rel_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Fsa_accepts_from_state_op_ctxt,rel_Fsa_accepts_from_state.createContext());
CREATE_OP_CONTEXT(rel_Fsa_tr_op_ctxt,rel_Fsa_tr.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_accepts_from_op_ctxt,rel__temp1_Fsa_accepts_from.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_accepts_from_op_ctxt,rel__temp2_Fsa_accepts_from.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_FsaState_vector) {
for(const auto& env2 : rel_Fsa_Word_sublist) {
if( !rel_Fsa_accepts_from_state.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env0[0],env2[0]})),env1[0]}),READ_OP_CONTEXT(rel_Fsa_accepts_from_state_op_ctxt))) {
const Tuple<RamDomain,3> key({env1[0],0,env0[0]});
auto range = rel_Fsa_tr.equalRange<0,2>(key,READ_OP_CONTEXT(rel_Fsa_tr_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,2> key({env2[0],env3[1]});
auto range = rel__temp1_Fsa_accepts_from.equalRange<0,1>(key,READ_OP_CONTEXT(rel__temp1_Fsa_accepts_from_op_ctxt));
if(!range.empty()) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env2[0]})),env1[0]});
rel__temp2_Fsa_accepts_from.insert(tuple,READ_OP_CONTEXT(rel__temp2_Fsa_accepts_from_op_ctxt));
}
}
}
}
}
}
PARALLEL_END;
}
();if(rel__temp2_Fsa_accepts_from.empty()) break;
rel_Fsa_accepts_from_state.insertAll(rel__temp2_Fsa_accepts_from);
rel__temp1_Fsa_accepts_from.purge();
if (!rel_FsaState_vector.empty()&&!rel_Fsa_Word_sublist.empty()&&!rel_Fsa_tr.empty()&&!rel__temp2_Fsa_accepts_from.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_FsaState_vector_op_ctxt,rel_FsaState_vector.createContext());
CREATE_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt,rel_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Fsa_accepts_from_state_op_ctxt,rel_Fsa_accepts_from_state.createContext());
CREATE_OP_CONTEXT(rel_Fsa_tr_op_ctxt,rel_Fsa_tr.createContext());
CREATE_OP_CONTEXT(rel__temp1_Fsa_accepts_from_op_ctxt,rel__temp1_Fsa_accepts_from.createContext());
CREATE_OP_CONTEXT(rel__temp2_Fsa_accepts_from_op_ctxt,rel__temp2_Fsa_accepts_from.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_FsaState_vector) {
for(const auto& env2 : rel_Fsa_Word_sublist) {
if( !rel_Fsa_accepts_from_state.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env0[0],env2[0]})),env1[0]}),READ_OP_CONTEXT(rel_Fsa_accepts_from_state_op_ctxt))) {
const Tuple<RamDomain,3> key({env1[0],0,env0[0]});
auto range = rel_Fsa_tr.equalRange<0,2>(key,READ_OP_CONTEXT(rel_Fsa_tr_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,2> key({env2[0],env3[1]});
auto range = rel__temp2_Fsa_accepts_from.equalRange<0,1>(key,READ_OP_CONTEXT(rel__temp2_Fsa_accepts_from_op_ctxt));
if(!range.empty()) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env2[0]})),env1[0]});
rel__temp1_Fsa_accepts_from.insert(tuple,READ_OP_CONTEXT(rel__temp1_Fsa_accepts_from_op_ctxt));
}
}
}
}
}
}
PARALLEL_END;
}
();if(rel__temp1_Fsa_accepts_from.empty()) break;
rel_Fsa_accepts_from_state.insertAll(rel__temp1_Fsa_accepts_from);
rel__temp2_Fsa_accepts_from.purge();
}
rel__temp1_Fsa_accepts_from.purge();
rel__temp2_Fsa_accepts_from.purge();
rel_FsaState_vector.purge();
rel_Fsa_final.purge();
if (!rel_Fsa_tr.empty()&&!rel_fsa_state_to_str.empty()) [&](){
auto part = rel_Fsa_tr.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_tr_op_ctxt,rel_Fsa_tr.createContext());
CREATE_OP_CONTEXT(rel_fsa_state_to_str_op_ctxt,rel_fsa_state_to_str.createContext());
CREATE_OP_CONTEXT(rel_fsa_tr_op_ctxt,rel_fsa_tr.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({env0[0],0});
auto range = rel_fsa_state_to_str.equalRange<0>(key,READ_OP_CONTEXT(rel_fsa_state_to_str_op_ctxt));
for(const auto& env1 : range) {
const Tuple<RamDomain,2> key({env0[1],0});
auto range = rel_fsa_state_to_str.equalRange<0>(key,READ_OP_CONTEXT(rel_fsa_state_to_str_op_ctxt));
for(const auto& env2 : range) {
Tuple<RamDomain,3> tuple({env1[1],env2[1],env0[2]});
rel_fsa_tr.insert(tuple,READ_OP_CONTEXT(rel_fsa_tr_op_ctxt));
}
}
}
PARALLEL_END;
}
();rel_fsa_state_to_str.purge();
rel_Fsa_tr.purge();
if (!rel_Fsa_Word_sublist.empty()&&!rel_Fsa_accepts_from_state.empty()&&!rel_Fsa_start_state.empty()) [&](){
auto part = rel_Fsa_Word_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_Word_sublist_op_ctxt,rel_Fsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Fsa_accepts_op_ctxt,rel_Fsa_accepts.createContext());
CREATE_OP_CONTEXT(rel_Fsa_accepts_from_state_op_ctxt,rel_Fsa_accepts_from_state.createContext());
CREATE_OP_CONTEXT(rel_Fsa_start_state_op_ctxt,rel_Fsa_start_state.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_Fsa_start_state) {
const Tuple<RamDomain,2> key({env0[0],env1[0]});
auto range = rel_Fsa_accepts_from_state.equalRange<0,1>(key,READ_OP_CONTEXT(rel_Fsa_accepts_from_state_op_ctxt));
if(!range.empty()) {
Tuple<RamDomain,1> tuple({env0[0]});
rel_Fsa_accepts.insert(tuple,READ_OP_CONTEXT(rel_Fsa_accepts_op_ctxt));
}
}
}
PARALLEL_END;
}
();rel_Fsa_Word_sublist.purge();
rel_Fsa_start_state.purge();
rel_Fsa_accepts_from_state.purge();
if (!rel_Fsa_accepts.empty()&&!rel_word_to_str.empty()) [&](){
auto part = rel_Fsa_accepts.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Fsa_accepts_op_ctxt,rel_Fsa_accepts.createContext());
CREATE_OP_CONTEXT(rel_fsa_accepted_op_ctxt,rel_fsa_accepted.createContext());
CREATE_OP_CONTEXT(rel_word_to_str_op_ctxt,rel_word_to_str.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({env0[0],0});
auto range = rel_word_to_str.equalRange<0>(key,READ_OP_CONTEXT(rel_word_to_str_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,1> tuple({env1[1]});
rel_fsa_accepted.insert(tuple,READ_OP_CONTEXT(rel_fsa_accepted_op_ctxt));
}
}
PARALLEL_END;
}
();rel_Fsa_accepts.purge();
rel_Nfsa_max_acceptance_siz.insert(5);
rel_Nfsa_Word_len.insert(0,0);
rel__temp1_Nfsa_Word_len.insertAll(rel_Nfsa_Word_len);
rel_Nfsa_Word_sublist.insert(0);
rel__temp1_Nfsa_Word_sublis.insertAll(rel_Nfsa_Word_sublist);
for(;;) {
SECTIONS_START;
SECTION_START;
if (!rel_Nfsa_Word_len.empty()&&!rel__temp1_Nfsa_Word_sublis.empty()) [&](){
auto part = rel__temp1_Nfsa_Word_sublis.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt,rel_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt,rel__temp1_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_Word_sublis_op_ctxt,rel__temp1_Nfsa_Word_sublis.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt,rel__temp2_Nfsa_Word_len.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel_Nfsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( ((!rel_Nfsa_Word_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt))) && (!rel__temp1_Nfsa_Word_len.contains(Tuple<RamDomain,2>({env1[1],env2[1]}),READ_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt))))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp2_Nfsa_Word_len.insert(tuple,READ_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();if (!rel_Nfsa_Word_sublist.empty()&&!rel__temp1_Nfsa_Word_len.empty()) [&](){
auto part = rel_Nfsa_Word_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt,rel_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt,rel_Nfsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt,rel__temp1_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt,rel__temp2_Nfsa_Word_len.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel__temp1_Nfsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel_Nfsa_Word_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp2_Nfsa_Word_len.insert(tuple,READ_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTION_START;
if (!rel_Nfsa_Word_len.empty()&&!rel_Nfsa_max_acceptance_siz.empty()&&!rel__temp1_Nfsa_Word_sublis.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt,rel_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt,rel_Nfsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_max_acceptance_siz_op_ctxt,rel_Nfsa_max_acceptance_siz.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt,rel__temp1_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_Word_sublis_op_ctxt,rel__temp1_Nfsa_Word_sublis.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_Word_sublis_op_ctxt,rel__temp2_Nfsa_Word_sublis.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel__temp1_Nfsa_Word_sublis) {
if( !rel_Nfsa_Word_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel_Nfsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel__temp1_Nfsa_Word_len.contains(Tuple<RamDomain,2>({env1[0],env2[1]}),READ_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt))) {
for(const auto& env3 : rel_Nfsa_max_acceptance_siz) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp2_Nfsa_Word_sublis.insert(tuple,READ_OP_CONTEXT(rel__temp2_Nfsa_Word_sublis_op_ctxt));
}
}
}
}
}
}
}
PARALLEL_END;
}
();if (!rel_Nfsa_Word_sublist.empty()&&!rel_Nfsa_max_acceptance_siz.empty()&&!rel__temp1_Nfsa_Word_len.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt,rel_Nfsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_max_acceptance_siz_op_ctxt,rel_Nfsa_max_acceptance_siz.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt,rel__temp1_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_Word_sublis_op_ctxt,rel__temp2_Nfsa_Word_sublis.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_Nfsa_Word_sublist) {
if( !rel_Nfsa_Word_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel__temp1_Nfsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
for(const auto& env3 : rel_Nfsa_max_acceptance_siz) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp2_Nfsa_Word_sublis.insert(tuple,READ_OP_CONTEXT(rel__temp2_Nfsa_Word_sublis_op_ctxt));
}
}
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTIONS_END;
if(((rel__temp2_Nfsa_Word_len.empty()) && (rel__temp2_Nfsa_Word_sublis.empty()))) break;
SECTIONS_START;
SECTION_START;
rel_Nfsa_Word_len.insertAll(rel__temp2_Nfsa_Word_len);
rel__temp1_Nfsa_Word_len.purge();
SECTION_END
SECTION_START;
rel_Nfsa_Word_sublist.insertAll(rel__temp2_Nfsa_Word_sublis);
rel__temp1_Nfsa_Word_sublis.purge();
SECTION_END
SECTIONS_END;
SECTIONS_START;
SECTION_START;
if (!rel_Nfsa_Word_len.empty()&&!rel__temp2_Nfsa_Word_sublis.empty()) [&](){
auto part = rel__temp2_Nfsa_Word_sublis.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt,rel_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt,rel__temp1_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt,rel__temp2_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_Word_sublis_op_ctxt,rel__temp2_Nfsa_Word_sublis.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel_Nfsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( ((!rel_Nfsa_Word_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt))) && (!rel__temp2_Nfsa_Word_len.contains(Tuple<RamDomain,2>({env1[1],env2[1]}),READ_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt))))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp1_Nfsa_Word_len.insert(tuple,READ_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();if (!rel_Nfsa_Word_sublist.empty()&&!rel__temp2_Nfsa_Word_len.empty()) [&](){
auto part = rel_Nfsa_Word_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt,rel_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt,rel_Nfsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt,rel__temp1_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt,rel__temp2_Nfsa_Word_len.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
auto ref = env0[0];
if (isNull<ram::Tuple<RamDomain,2>>(ref)) continue;
ram::Tuple<RamDomain,2> env1 = unpack<ram::Tuple<RamDomain,2>>(ref);
{
const Tuple<RamDomain,2> key({env1[1],0});
auto range = rel__temp2_Nfsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel_Nfsa_Word_len.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)}),READ_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt))) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env1[0],env1[1]})),(env2[1]) + (1)});
rel__temp1_Nfsa_Word_len.insert(tuple,READ_OP_CONTEXT(rel__temp1_Nfsa_Word_len_op_ctxt));
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTION_START;
if (!rel_Nfsa_Word_len.empty()&&!rel_Nfsa_max_acceptance_siz.empty()&&!rel__temp2_Nfsa_Word_sublis.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt,rel_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt,rel_Nfsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_max_acceptance_siz_op_ctxt,rel_Nfsa_max_acceptance_siz.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_Word_sublis_op_ctxt,rel__temp1_Nfsa_Word_sublis.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt,rel__temp2_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_Word_sublis_op_ctxt,rel__temp2_Nfsa_Word_sublis.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel__temp2_Nfsa_Word_sublis) {
if( !rel_Nfsa_Word_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel_Nfsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel_Nfsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
if( !rel__temp2_Nfsa_Word_len.contains(Tuple<RamDomain,2>({env1[0],env2[1]}),READ_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt))) {
for(const auto& env3 : rel_Nfsa_max_acceptance_siz) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp1_Nfsa_Word_sublis.insert(tuple,READ_OP_CONTEXT(rel__temp1_Nfsa_Word_sublis_op_ctxt));
}
}
}
}
}
}
}
PARALLEL_END;
}
();if (!rel_Nfsa_Word_sublist.empty()&&!rel_Nfsa_max_acceptance_siz.empty()&&!rel__temp2_Nfsa_Word_len.empty()&&!rel_alphabet.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt,rel_Nfsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_max_acceptance_siz_op_ctxt,rel_Nfsa_max_acceptance_siz.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_Word_sublis_op_ctxt,rel__temp1_Nfsa_Word_sublis.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt,rel__temp2_Nfsa_Word_len.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_Nfsa_Word_sublist) {
if( !rel_Nfsa_Word_sublist.contains(Tuple<RamDomain,1>({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))}),READ_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt))) {
const Tuple<RamDomain,2> key({env1[0],0});
auto range = rel__temp2_Nfsa_Word_len.equalRange<0>(key,READ_OP_CONTEXT(rel__temp2_Nfsa_Word_len_op_ctxt));
for(const auto& env2 : range) {
for(const auto& env3 : rel_Nfsa_max_acceptance_siz) {
if( ((env2[1]) < (env3[0]))) {
Tuple<RamDomain,1> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env1[0]}))});
rel__temp1_Nfsa_Word_sublis.insert(tuple,READ_OP_CONTEXT(rel__temp1_Nfsa_Word_sublis_op_ctxt));
}
}
}
}
}
}
PARALLEL_END;
}
();SECTION_END
SECTIONS_END;
if(((rel__temp1_Nfsa_Word_len.empty()) && (rel__temp1_Nfsa_Word_sublis.empty()))) break;
SECTIONS_START;
SECTION_START;
rel_Nfsa_Word_len.insertAll(rel__temp1_Nfsa_Word_len);
rel__temp2_Nfsa_Word_len.purge();
SECTION_END
SECTION_START;
rel_Nfsa_Word_sublist.insertAll(rel__temp1_Nfsa_Word_sublis);
rel__temp2_Nfsa_Word_sublis.purge();
SECTION_END
SECTIONS_END;
}
rel__temp1_Nfsa_Word_len.purge();
rel__temp2_Nfsa_Word_len.purge();
rel__temp1_Nfsa_Word_sublis.purge();
rel__temp2_Nfsa_Word_sublis.purge();
rel_Nfsa_max_acceptance_siz.purge();
rel_Nfsa_Word_len.purge();
if (!rel_Nfsa_final.empty()) [&](){
auto part = rel_Nfsa_final.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_accepts_from_state_op_ctxt,rel_Nfsa_accepts_from_state.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_final_op_ctxt,rel_Nfsa_final.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
Tuple<RamDomain,2> tuple({0,env0[0]});
rel_Nfsa_accepts_from_state.insert(tuple,READ_OP_CONTEXT(rel_Nfsa_accepts_from_state_op_ctxt));
}
PARALLEL_END;
}
();rel__temp1_Nfsa_accepts_fro.insertAll(rel_Nfsa_accepts_from_state);
for(;;) {
if (!rel_Nfsa_Word_sublist.empty()&&!rel__temp1_Nfsa_accepts_fro.empty()&&!rel_alphabet.empty()&&!rel_state.empty()&&!rel_tr.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt,rel_Nfsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_accepts_from_state_op_ctxt,rel_Nfsa_accepts_from_state.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_accepts_fro_op_ctxt,rel__temp1_Nfsa_accepts_fro.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_accepts_fro_op_ctxt,rel__temp2_Nfsa_accepts_fro.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
CREATE_OP_CONTEXT(rel_state_op_ctxt,rel_state.createContext());
CREATE_OP_CONTEXT(rel_tr_op_ctxt,rel_tr.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_state) {
for(const auto& env2 : rel_Nfsa_Word_sublist) {
if( !rel_Nfsa_accepts_from_state.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env0[0],env2[0]})),env1[0]}),READ_OP_CONTEXT(rel_Nfsa_accepts_from_state_op_ctxt))) {
const Tuple<RamDomain,3> key({env1[0],0,env0[0]});
auto range = rel_tr.equalRange<0,2>(key,READ_OP_CONTEXT(rel_tr_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,2> key({env2[0],env3[1]});
auto range = rel__temp1_Nfsa_accepts_fro.equalRange<0,1>(key,READ_OP_CONTEXT(rel__temp1_Nfsa_accepts_fro_op_ctxt));
if(!range.empty()) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env2[0]})),env1[0]});
rel__temp2_Nfsa_accepts_fro.insert(tuple,READ_OP_CONTEXT(rel__temp2_Nfsa_accepts_fro_op_ctxt));
}
}
}
}
}
}
PARALLEL_END;
}
();if(rel__temp2_Nfsa_accepts_fro.empty()) break;
rel_Nfsa_accepts_from_state.insertAll(rel__temp2_Nfsa_accepts_fro);
rel__temp1_Nfsa_accepts_fro.purge();
if (!rel_Nfsa_Word_sublist.empty()&&!rel__temp2_Nfsa_accepts_fro.empty()&&!rel_alphabet.empty()&&!rel_state.empty()&&!rel_tr.empty()) [&](){
auto part = rel_alphabet.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt,rel_Nfsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_accepts_from_state_op_ctxt,rel_Nfsa_accepts_from_state.createContext());
CREATE_OP_CONTEXT(rel__temp1_Nfsa_accepts_fro_op_ctxt,rel__temp1_Nfsa_accepts_fro.createContext());
CREATE_OP_CONTEXT(rel__temp2_Nfsa_accepts_fro_op_ctxt,rel__temp2_Nfsa_accepts_fro.createContext());
CREATE_OP_CONTEXT(rel_alphabet_op_ctxt,rel_alphabet.createContext());
CREATE_OP_CONTEXT(rel_state_op_ctxt,rel_state.createContext());
CREATE_OP_CONTEXT(rel_tr_op_ctxt,rel_tr.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_state) {
for(const auto& env2 : rel_Nfsa_Word_sublist) {
if( !rel_Nfsa_accepts_from_state.contains(Tuple<RamDomain,2>({pack(ram::Tuple<RamDomain,2>({env0[0],env2[0]})),env1[0]}),READ_OP_CONTEXT(rel_Nfsa_accepts_from_state_op_ctxt))) {
const Tuple<RamDomain,3> key({env1[0],0,env0[0]});
auto range = rel_tr.equalRange<0,2>(key,READ_OP_CONTEXT(rel_tr_op_ctxt));
for(const auto& env3 : range) {
const Tuple<RamDomain,2> key({env2[0],env3[1]});
auto range = rel__temp2_Nfsa_accepts_fro.equalRange<0,1>(key,READ_OP_CONTEXT(rel__temp2_Nfsa_accepts_fro_op_ctxt));
if(!range.empty()) {
Tuple<RamDomain,2> tuple({pack(ram::Tuple<RamDomain,2>({env0[0],env2[0]})),env1[0]});
rel__temp1_Nfsa_accepts_fro.insert(tuple,READ_OP_CONTEXT(rel__temp1_Nfsa_accepts_fro_op_ctxt));
}
}
}
}
}
}
PARALLEL_END;
}
();if(rel__temp1_Nfsa_accepts_fro.empty()) break;
rel_Nfsa_accepts_from_state.insertAll(rel__temp1_Nfsa_accepts_fro);
rel__temp2_Nfsa_accepts_fro.purge();
}
rel__temp1_Nfsa_accepts_fro.purge();
rel__temp2_Nfsa_accepts_fro.purge();
rel_Nfsa_final.purge();
rel_tr.purge();
rel_state.purge();
rel_alphabet.purge();
if (!rel_Nfsa_Word_sublist.empty()&&!rel_Nfsa_accepts_from_state.empty()&&!rel_Nfsa_start_state.empty()) [&](){
auto part = rel_Nfsa_Word_sublist.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_Word_sublist_op_ctxt,rel_Nfsa_Word_sublist.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_accepts_op_ctxt,rel_Nfsa_accepts.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_accepts_from_state_op_ctxt,rel_Nfsa_accepts_from_state.createContext());
CREATE_OP_CONTEXT(rel_Nfsa_start_state_op_ctxt,rel_Nfsa_start_state.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
for(const auto& env1 : rel_Nfsa_start_state) {
const Tuple<RamDomain,2> key({env0[0],env1[0]});
auto range = rel_Nfsa_accepts_from_state.equalRange<0,1>(key,READ_OP_CONTEXT(rel_Nfsa_accepts_from_state_op_ctxt));
if(!range.empty()) {
Tuple<RamDomain,1> tuple({env0[0]});
rel_Nfsa_accepts.insert(tuple,READ_OP_CONTEXT(rel_Nfsa_accepts_op_ctxt));
}
}
}
PARALLEL_END;
}
();rel_Nfsa_start_state.purge();
rel_Nfsa_accepts_from_state.purge();
rel_Nfsa_Word_sublist.purge();
if (!rel_Nfsa_accepts.empty()&&!rel_word_to_str.empty()) [&](){
auto part = rel_Nfsa_accepts.partition();
PARALLEL_START;
CREATE_OP_CONTEXT(rel_Nfsa_accepts_op_ctxt,rel_Nfsa_accepts.createContext());
CREATE_OP_CONTEXT(rel_nfsa_accepted_op_ctxt,rel_nfsa_accepted.createContext());
CREATE_OP_CONTEXT(rel_word_to_str_op_ctxt,rel_word_to_str.createContext());
pfor(auto it = part.begin(); it<part.end(); ++it) 
for(const auto& env0 : *it) {
const Tuple<RamDomain,2> key({env0[0],0});
auto range = rel_word_to_str.equalRange<0>(key,READ_OP_CONTEXT(rel_word_to_str_op_ctxt));
for(const auto& env1 : range) {
Tuple<RamDomain,1> tuple({env1[1]});
rel_nfsa_accepted.insert(tuple,READ_OP_CONTEXT(rel_nfsa_accepted_op_ctxt));
}
}
PARALLEL_END;
}
();rel_Nfsa_accepts.purge();
rel_word_to_str.purge();
}
public:
void printAll(std::string dirname=".") {
rel_fsa_accepted.printCSV(dirname + "/fsa_accepted.csv",symTable,1);
rel_fsa_tr.printCSV(dirname + "/fsa_tr.csv",symTable,1,1,1);
rel_nfsa_accepted.printCSV(dirname + "/nfsa_accepted.csv",symTable,1);
}
public:
void loadAll(std::string dirname=".") {
rel_tr.loadCSV(dirname + "/tr.facts",symTable,0,0,1);
}
public:
void dumpInputs(std::ostream& out = std::cout) {
out << "---------------\ntr\n===============\n";
rel_tr.printCSV(out,symTable,0,0,1);
out << "===============\n";
}
public:
void dumpOutputs(std::ostream& out = std::cout) {
out << "---------------\nfsa_accepted\n===============\n";
rel_fsa_accepted.printCSV(out,symTable,1);
out << "===============\n";
out << "---------------\nfsa_tr\n===============\n";
rel_fsa_tr.printCSV(out,symTable,1,1,1);
out << "===============\n";
out << "---------------\nnfsa_accepted\n===============\n";
rel_nfsa_accepted.printCSV(out,symTable,1);
out << "===============\n";
}
public:
void dumpDB(std::string filename, bool outputRelationsOnly) {
writeRelationsToSqlite(filename, this, outputRelationsOnly);
}
public:
const SymbolTable &getSymbolTable() const {
return symTable;
}
};
SouffleProgram *newInstance_nfsa2fsa_auto(){return new Sf_nfsa2fsa_auto;}
SymbolTable *getST_nfsa2fsa_auto(SouffleProgram *p){return &reinterpret_cast<Sf_nfsa2fsa_auto*>(p)->symTable;}
#ifdef __EMBEDDED_SOUFFLE__
class factory_Sf_nfsa2fsa_auto: public souffle::ProgramFactory {
SouffleProgram *newInstance() {
return new Sf_nfsa2fsa_auto();
};
public:
factory_Sf_nfsa2fsa_auto() : ProgramFactory("nfsa2fsa_auto"){}
};
static factory_Sf_nfsa2fsa_auto __factory_Sf_nfsa2fsa_auto_instance;
}
#else
}
int main(int argc, char** argv)
{
souffle::CmdOptions opt(R"(nfsa2fsa.dl)",
R"(./facts)",
R"(.)",
false,
R"()",
R"()",
1,
R"(false)");
if (!opt.parse(argc,argv)) return 1;
#if defined(_OPENMP) 
omp_set_nested(true);
#endif
souffle::Sf_nfsa2fsa_auto obj;
obj.loadAll(opt.getInputFileDir());
obj.run();
if (!opt.getOutputFileDir().empty()) obj.printAll(opt.getOutputFileDir());
if (!opt.getOutputDatabaseName().empty()) obj.dumpDB(opt.getOutputDatabaseName(), 1);
return 0;
}
#endif
