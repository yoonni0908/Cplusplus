#include <iostream>
#include "HTMLWriter.h"
using namespace std;

void showFileContent(const DocWriter& doc) {
	doc.readFile();
}

int main() {

	DocWriter doc1("doctest.txt", "greenjoa");
	HTMLWriter html1("htmltest.html", "konkuk");

	showFileContent(doc1);
	showFileContent(html1); //DocWriter& doc1 = html1;과 같은 원리

}