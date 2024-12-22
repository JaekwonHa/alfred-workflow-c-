# alfred-workflow-c++

```bash
brew install cmake
brew install autoconf automake autoconf-archive libtool

~/vcpkg/vcpkg x-update-baseline --add-initial-baseline

cmake --list-presets
cmake --preset release
cmake --build --preset release-build

./bin/Release/open_project_in_vscode bin/Release/vscode_project
```

## vscode로 프로젝트 열기

로컬 경로 + 리모트 경로 둘다 지원

파일 경로를 입력 받는다. 파일을 읽는다 -> 검색어와 매칭되는 프로젝트명이 있는지, 있는 것만 리스트로 뽑음. 필터 파이프라인 사용하면 될듯
-> 리스트를 json으로 출력
coroutine 적용해보기?

테스트 항목
* 파일 경로를 입력했을때, 읽는 내용이 정확힌지
* 파일 리스트가 있고 검색어를 줬을때, 필터링되는게 정확한지
* 파일 리스트를 입력 받았을때, alfred output 형태로 스키마가 제대로 나오는지

## 복사하면 문자열에 따라서 특정 액션 수행

* url 형태라면 크롬에서 오픈
* 커맨드 형태라면 커맨드만 따서 클립보드에 복사

## url 한꺼번에 열기

특정 경로에 key: URL 링크들. 구조의 파일이 있다
key 목록을 보여주고 key를 선택했을때 URL 링크들이 모두 열린다
