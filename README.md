# HW10_ModuleAndPlugin

언리얼 엔진 C++에서 **모듈(Module)**과 **플러그인(Plugin)**을 생성하고 활용하는 방법을 학습하는 프로젝트입니다.

---

## 📌 프로젝트 개요
이 프로젝트는 언리얼 엔진의 모듈화 시스템과 플러그인 구조를 이해하고 실습하기 위해 제작되었습니다. 코드를 독립적인 단위로 분리하여 유지보수성과 재사용성을 극대화하는 방법을 다룹니다.

---

## 🛠️ 주요 내용

### 1. 모듈 (Module)
* **정의**: 언리얼 프로젝트의 기본 구성 단위로, 코드를 논리적으로 분리하여 관리합니다.
* **특징**:
  * 각 모듈은 독립적인 컴파일 단위입니다.
  * `.Build.cs` 파일로 모듈 간의 의존성을 관리합니다.
  * 프로젝트 내부에서 직접 사용됩니다.

### 2. 플러그인 (Plugin)
* **정의**: 재사용 가능한 독립적인 기능 단위로, 여러 다른 프로젝트에서도 쉽게 공유하고 이식할 수 있습니다.
* **특징**:
  * 하나 이상의 모듈을 포함할 수 있는 더 큰 상위 개념입니다.
  * `.uplugin` 파일로 플러그인의 메타데이터를 관리합니다.
  * Content Browser에서 별도로 관리됩니다. (확인을 위해 `Show Plugin Content` 활성화가 필요합니다.)

---

## 📂 프로젝트 구조

```text
HW10_ModuleAndPlugin/
├── Source/
│   ├── ModuleAndPlugin/         # 기본 프로젝트 모듈
│   └── Test/                    # Test 추가 모듈
│       └── Data/
│           ├── CharacterData.h           # 플레이어 정보 클래스 (기본/전투/속성/경험치/장비 정보)
│           ├── CharacterData.cpp
│           ├── CharacterDataHelper.h     # 플레이어 Data 로그 출력 헬퍼 클래스 (UBlueprintFunctionLibrary 상속)
│           └── CharacterDataHelper.cpp
├── Plugins/
│   └── Temporary/               # 실습용 플러그인
├── Content/
└── ModuleAndPlugin.uproject
```

---

## ⚙️ 설정 방법

### 모듈 추가 시
1. `Source/` 폴더에 새 모듈 디렉토리를 생성합니다.
2. `.Build.cs` 파일을 작성합니다.
3. `.uproject` 파일의 `Modules` 배열에 등록합니다.

### 플러그인 추가 시
1. 에디터를 통한 생성을 권장합니다. (`Edit > Plugins > New Plugin`)
2. `.uplugin` 파일 및 모듈 구조가 자동으로 생성됩니다.
3. `.uproject` 파일의 `Plugins` 배열에 등록합니다.
4. **주의**: `AdditionalDependencies`에 플러그인 모듈 추가가 필요합니다.

---

## ⚠️ 주의사항

* **새로운 모듈에 언리얼 오브젝트 클래스가 없으면** 에디터에서 보이지 않을 수 있습니다.
* **플러그인 콘텐츠 확인 시** Content Browser 설정에서 `Show Plugin Content` 활성화가 필수적입니다.
* **PROJECE 재생성 시** `.vs`, `Binaries`, `DerivedDataCache`, `Intermediate`, `Saved` 폴더를 완전히 삭제한 후 진행해야 안전합니다.

---

## 📖 정리 TIL

* [[UE, C++] 언리얼 모듈(Module)과 플러그인(Plugin)](https://velog.io/@kimsn3464/UE-C-%EC%96%B8%EB%A6%AC%EC%96%BC-%EB%AA%A8%EB%93%88Module%EA%B3%BC-%ED%94%8C%EB%9F%AC%EA%B7%B8%EC%9D%B8Plugin)
